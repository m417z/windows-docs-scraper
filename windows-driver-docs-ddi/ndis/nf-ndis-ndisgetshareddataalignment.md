# NdisGetSharedDataAlignment function

## Description

**NdisGetSharedDataAlignment** returns the preferred alignment for memory structures that can be shared
by more than one processor.

## Return value

The boundary value, in bytes, on which drivers should align structures that can be shared by more
than one processor.

## Remarks

Use
**NdisGetSharedDataAlignment** to determine the best alignment for data structures that will be shared
between processors. Using the returned value when allocating such structures minimizes cache effects that
reduce the performance of multiprocessor systems.

System support for
**NdisGetSharedDataAlignment** is available in Windows XP and later versions.