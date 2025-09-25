# _NDK_MW structure

## Description

The **NDK_MW** structure specifies the attributes of an NDK memory window (MW) object.

## Members

### `Header`

The [NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header) structure for the **NDK_MW** structure. Set the **ObjectType** member of the structure that **Header** specifies to **NdkObjectTypeMw**.

### `Dispatch`

A pointer to an [NDK_MW_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mw_dispatch) structure that defines dispatch functions for the NDK MW object.

## Remarks

An NDK provider must set the **Dispatch** member to point to its [NDK_MW_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mw_dispatch) table before returning the created MW object. Also, the NDK provider must not use the **Dispatch** member after setting it because the NDK consumer can change the **Dispatch** member to some other value.

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object)

[NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)

[NDK_FN_CREATE_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_mw)

[NDK_MW_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mw_dispatch)

[NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header)