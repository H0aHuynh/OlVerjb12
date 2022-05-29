#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>             // uint*_t
#include <stdbool.h>
#include <mach-o/loader.h>
#ifdef __OBJC__
#include <Foundation/Foundation.h>
#define LOG(str, args...) do { NSLog(@"[*] " str "\n", ##args); } while(false)
#else
#include <CoreFoundation/CoreFoundation.h>
extern void NSLog(CFStringRef, ...);
#define LOG(str, args...) do { NSLog(CFSTR("[*] " str "\n"), ##args); } while(false)
#endif
#define ADDR                 "0x%016llx"


typedef uint64_t kptr_t;
struct exploit_common_s {
    bool debug;
    bool has_PAC;
    const char *model;
    const char *osversion;
    const char *osproductversion;
    const char *machine;
    const char *kern_version;

    int64_t physmemsize;
    uint64_t pagesize;

};

extern struct exploit_common_s g_exp;

void sys_init(void);
void print_os_details(void);
#define KPTR_NULL ((kptr_t) 0)
#define KERN_POINTER_VALID(val) ((val) >= 0xffff000000000000 && (val) != 0xffffffffffffffff)
#define SafeFree(x) do { if (x) free(x); } while(false)
#define SafeFreeNULL(x) do { SafeFree(x); (x) = NULL; } while(false)

#endif
