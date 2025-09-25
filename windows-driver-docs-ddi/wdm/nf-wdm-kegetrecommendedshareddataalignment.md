# KeGetRecommendedSharedDataAlignment function

## Description

The **KeGetRecommendedSharedDataAlignment** routine returns the preferred alignment for memory structures that can be accessed by more than one processor.

## Return value

**KeGetRecommendedSharedDataAlignment** returns the preferred alignment, in bytes, for memory structures that can be shared by more than one processor.

## Remarks

Use **KeGetRecommendedSharedDataAlignment** to determine the best alignment for data structures that will be shared between processors. The value returned minimizes cache effects that negatively impact performance on multiprocessor systems.