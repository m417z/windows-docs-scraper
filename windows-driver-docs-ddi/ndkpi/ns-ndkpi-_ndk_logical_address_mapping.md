# _NDK_LOGICAL_ADDRESS_MAPPING structure

## Description

The **NDK_LOGICAL_ADDRESS_MAPPING** structure contains an array of adapter logical addresses.

## Members

### `AdapterContext`

Reserved for the NDK provider's use. The NDK consumer must not modify this member.

### `AdapterPageCount`

 The number of entries in the array that is specified in the **AdapterPageArray** member.

### `AdapterPageArray`

An array of adapter logical addresses. Each logical address in the array corresponds to a page, of **PAGE_SIZE** bytes in length, and must be **PAGE_SIZE**-aligned. The array of pages correspond to a virtually contiguous memory region.
The **NDK_LOGICAL_ADDRESS** datatype is defined as follows:

```
typedef PHYSICAL_ADDRESS NDK_LOGICAL_ADDRESS;
```

## Remarks

**NDK_LOGICAL_ADDRESS_MAPPING** represents an adapter's view of physical memory. See [NDK_FN_BUILD_LAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_build_lam) and [NDK_FN_RELEASE_LAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_release_lam) for more information.

## See also

[NDK_FN_BUILD_LAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_build_lam)

[NDK_FN_RELEASE_LAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_release_lam)