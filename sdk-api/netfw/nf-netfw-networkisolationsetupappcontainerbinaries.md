# NetworkIsolationSetupAppContainerBinaries function

## Description

The **NetworkIsolationSetupAppContainerBinaries** function is used by software installers to provide information about the image paths of applications that are running in an app container. This information is provided to third-party firewall applications about the applications in order to enhance user experience and security decisions.

## Parameters

### `applicationContainerSid` [in]

Type: **PSID**

The package identifier of the app container.

### `packageFullName` [in]

Type: **LPCWSTR**

A string representing the package identity of the app that owns this app container. Contains the 5-part tuple as individual fields (name, version, architecture, resourceid, publisher).

### `packageFolder` [in]

Type: **LPCWSTR**

The file location of the app that owns this app container.

### `displayName` [in]

Type: **LPCWSTR**

The friendly name of the app container.

### `bBinariesFullyComputed` [in]

Type: **BOOL**

True if the binary files are being provided by the caller; otherwise, false.

### `binaries` [in]

Type: **LPCWSTR***

An array of paths to the applications running in the app container.

### `binariesCount` [in]

Type: **DWORD**

The number of paths contained in the *binaries* parameter.

## Return value

Type: **HRESULT**

If the function succeeds, it returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Applications creating an app container can use **NetworkIsolationSetupAppContainerBinaries** to provide third-party firewall applications with the direct path to applications running inside that app container.