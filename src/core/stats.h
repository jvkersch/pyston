// Copyright (c) 2014-2015 Dropbox, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef PYSTON_CORE_STATS_H
#define PYSTON_CORE_STATS_H

#include <atomic>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>

#include "core/options.h"

namespace pyston {

#define DISABLE_STATS 0

#if !DISABLE_STATS
struct Stats {
private:
    static std::vector<long>* counts;
    static std::unordered_map<int, std::string>* names;
    static bool enabled;

public:
    static int getStatId(const std::string& name);

    static void setEnabled(bool enabled) { Stats::enabled = enabled; }
    static void log(int id, int count = 1) { (*counts)[id] += count; }

    static void clear() { std::fill(counts->begin(), counts->end(), 0); }
    static void dump(bool includeZeros = true);
    static void endOfInit();
};

struct StatCounter {
private:
    int id;

public:
    StatCounter(const std::string& name);

    void log(int count = 1) { Stats::log(id, count); }
};

struct StatPerThreadCounter {
private:
    int id = 0;

public:
    StatPerThreadCounter(const std::string& name);

    void log(int count = 1) { Stats::log(id, count); }
};

#else
struct Stats {
    static void setEnabled(bool enabled) {}
    static void dump() { printf("(Stats disabled)\n"); }
    static void log(int id, int count = 1) {}
    static int getStatId(const std::string& name) { return 0; }
    static void endOfInit() {}
};
struct StatCounter {
    StatCounter(const char* name) {}
    void log(int count = 1){};
};
struct StatPerThreadCounter {
    StatPerThreadCounter(const char* name) {}
    void log(int count = 1){};
};
#endif
}

#endif
