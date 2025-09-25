# GetStagedPackageOrigin function

## Description

Gets the origin of the specified package.

## Parameters

### `packageFullName` [in]

Type: **PCWSTR**

The full name of the package.

### `origin` [out]

Type: **[PackageOrigin](https://learn.microsoft.com/windows/desktop/api/appmodel/ne-appmodel-packageorigin)***

A pointer to a variable that receives a [PackageOrigin](https://learn.microsoft.com/windows/desktop/api/appmodel/ne-appmodel-packageorigin)-typed value that indicates the origin of the package specified by *packageFullName*.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *packageFullName* parameter isn't valid. |