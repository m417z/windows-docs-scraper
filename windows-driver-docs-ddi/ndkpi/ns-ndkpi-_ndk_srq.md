# _NDK_SRQ structure

## Description

The **NDK_SRQ** structure specifies the attributes of an NDK shared receive queue (SRQ) object.

## Members

### `Header`

The [NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header) structure for the NDK_SRQ structure. Set the **ObjectType** member of the structure that **Header** specifies to **NdkObjectTypeSrq**.

### `Dispatch`

A pointer to an [NDK_SRQ_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_srq_dispatch) structure that defines dispatch functions for the NDK SRQ object.

## Remarks

An NDK provider must set the **Dispatch** member to point to its [NDK_SRQ_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_srq_dispatch) table before returning the created SRQ object. Also, the NDK provider must not use the **Dispatch** member after setting it because the NDK consumer can change the **Dispatch** member to some other value.

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDKPI Work Request Posting Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-work-request-posting-requirements)

[NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object)

[NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)

[NDK_FN_CREATE_QP_WITH_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_qp_with_srq)

[NDK_FN_CREATE_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_srq)

[NDK_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header)

[NDK_SRQ_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_srq_dispatch)