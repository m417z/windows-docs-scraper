# ExConvertExclusiveToSharedLite function

## Description

The **ExConvertExclusiveToSharedLite** routine converts a given resource from acquired for exclusive access to acquired for shared access.

## Parameters

### `Resource` [in, out]

A pointer to the resource for which the access should be converted.

## Remarks

The caller must have exclusive access to the given resource. During this conversion, the current thread and any other threads waiting for shared access to the resource are given shared access.

## See also

[ExIsResourceAcquiredExclusiveLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exisresourceacquiredexclusivelite)