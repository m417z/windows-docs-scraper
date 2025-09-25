# YieldProcessor function

## Description

Signals to the processor to give resources to threads that are waiting for them. This macro is only effective on processors that support technology allowing multiple threads running on a single processor, such as Intel's Hyperthreading technology.

## Remarks

This macro can be called on all processor platforms where Windows is supported, but it has no effect on some platforms. The definition varies from platform to platform. The following are some definitions of this macro in Winnt.h:

``` syntax
#define YieldProcessor() __asm { rep nop }

#define YieldProcessor _mm_pause

#define YieldProcessor __yield

```