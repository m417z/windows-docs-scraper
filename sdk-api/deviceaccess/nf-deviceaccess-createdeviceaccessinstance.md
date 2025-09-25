# CreateDeviceAccessInstance function

## Description

Creates the object that's used to access a device. The instantiated object implements the [IDeviceIoControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nn-deviceaccess-ideviceiocontrol) and [ICreateDeviceAccessAsync](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nn-deviceaccess-icreatedeviceaccessasync) interfaces.

Conditions (FYI):

```

 !defined(__deviceaccess_h__) [-AND-]  ((NTDDI_VERSION >= NTDDI_WIN8)) [-AND-]  defined(__cplusplus)
```

Declaration from header.

```

 HRESULT WINAPI
CreateDeviceAccessInstance(
    _In_ LPCWSTR deviceInterfacePath,
    _In_ DWORD desiredAccess,
    _Outptr_ ICreateDeviceAccessAsync **createAsync
    );
```

## Parameters

### `deviceInterfacePath` [in]

A valid device interface path for the device that this instance should bind to.

### `desiredAccess` [in]

The requested level of access to the device, which can be summarized as read, write, both, or neither (zero).

The most commonly used values are **GENERIC_READ**, **GENERIC_WRITE**, or both (**GENERIC_READ** | **GENERIC_WRITE**). For more information, see [Generic Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/generic-access-rights), [File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights), [File Access Rights Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-access-rights-constants), [Creating and Opening Files](https://learn.microsoft.com/windows/desktop/FileIO/creating-and-opening-files), and [ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask).

### `createAsync`

Asynchronous interface to control binding for this instance. For more information, see [ICreateDeviceAccessAsync](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nn-deviceaccess-icreatedeviceaccessasync).

## Return value

**S_OK** if the underlying object and asynchronous operation are created successfully; an appropriate error otherwise. Note that this function doesn't perform the actual binding.That happens as part of the asynchronous operation.