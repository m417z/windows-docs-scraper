# RtlQueryPackageIdentityEx function

## Description

**RtlQueryPackageIdentityEx** returns the associated full package name. It can optionally also return the package relative application name, and whether an application is considered packaged.

## Parameters

### `TokenObject`

Handle to a token object (user mode) that was opened with TOKEN_QUERY access, or to a raw token object (kernel mode).

### `PackageFullName`

Pointer to a wide character buffer that will receive the unique package key. The buffer will be null terminated upon success.

### `PackageSize`

Pointer to the value that defines the size of the buffer that *PackageFullName* points to. On output, it will contain the written size including the terminating null.

### `AppId`

Pointer to a wide character buffer that may receive the package relative application identifier. *AppId* is optional and can be **NULL**.

### `AppIdSize`

Pointer to the value that defines the size of the buffer that *AppId* points to. On output, it will contain the written size including the terminating null. If **AppId** is not **NULL**, **AppIdSize** must point to a valid value; otherwise **AppIdSize** should set to **NULL**.

### `DynamicId`

Pointer to a value that receives a dynamic ID for the application. *DynamicId* is optional and can be **NULL**.

### `Flags`

Pointer to a value that receives a bitmask of values for the package attribute.

## Return value

**RtlQueryPackageIdentityEx** returns STATUS_SUCCESS upon successful completion; otherwise it returns a code such as one of the following.

| Error Code | Meaning |
| ---------- | ------- |
| STATUS_INVALID_PARAMETER | A parameter contains an invalid value; for example, a size value was not provided for a non-NULL buffer. This is an error code. |
| STATUS_NOT_FOUND | A package identity does not exist. |

## Remarks

## See also