# _NDK_OBJECT_HEADER structure

## Description

The **NDK_OBJECT_HEADER** structure specifies the object version, type, and other information.

It is used in the **Header** member of every NDK object.

## Members

### `Version`

An [NDK_VERSION](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_version) structure that contains the revision number of the NDK object.

### `ObjectType`

An [NDK_OBJECT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ne-ndkpi-_ndk_object_type) enumeration value that specifies the NDK object type. You can use this member to identify an NDK object's type in a memory dump.

This member is required and cannot be zero.

### `NdkReserved`

A reserved block in an [NDK_OBJECT_HEADER_RESERVED_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header_reserved_block) structure.

## Remarks

When an NDK provider creates an NDK object instance, the **Header** member must be initialized as follows:

* For Windows Server 2012, set the **Version** member to 1.1. To do this, set both the **Major** and **Minor** members of the [NDK_VERSION](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_version) structure to 1.
* For Windows Server 2012 R2, set the **Version** member to 1.2. To do this, set the **Major** member of the [NDK_VERSION](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_version) structure to 1 and the **Minor** member to 2.
* Set the **ObjectType** member to an [NDK_OBJECT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ne-ndkpi-_ndk_object_type) value.
* Set the **NdkReserved** member to zero. The NDK provider must not modify this member until the object is closed.

## See also

[NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter)

[NDK_CONNECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_connector)

[NDK_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq)

[NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object)

[NDK_FN_CREATE_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_create_completion)

[NDK_FN_INVALIDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_invalidate)

[NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface)

[NDK_LISTENER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_listener)

[NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr)

[NDK_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mw)

[NDK_OBJECT_HEADER_RESERVED_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_object_header_reserved_block)

[NDK_OBJECT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ne-ndkpi-_ndk_object_type)

[NDK_PD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_pd)

[NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)

[NDK_SHARED_ENDPOINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_shared_endpoint)

[NDK_SRQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_srq)

[NDK_VERSION](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_version)