# IWDFDriver::RetrieveVersionString

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **RetrieveVersionString** method retrieves the version of the framework.

## Parameters

### `pVersion` [out]

A pointer to a buffer that receives a **NULL**-terminated string that represents the version of the framework if the supplied buffer is non-**NULL** and **RetrieveVersionString** is successful.

### `pdwVersionLength` [in, out]

A pointer to a variable that receives the size, in characters, of the version string that *pVersion* points to. On input, this variable contains the size, in bytes, of the buffer at *pVersion*.

If the buffer at *pVersion* is **NULL**, the value that the driver supplies is zero. The framework then returns the size, in characters, that is required for the version string.

If the buffer at *pVersion* is non-**NULL**, the framework returns the size, in characters, of the version string.

## Return value

**RetrieveVersionString** returns S_OK for the following scenarios:

* The buffer that the *pVersion* parameter points to was non-**NULL** and large enough to hold the version string, including the **NULL** character. In addition, the framework successfully copied the string into the supplied buffer and set the variable that is pointed to by the *pdwVersionLength* parameter to the number of characters in the string.
* The buffer at *pVersion* was **NULL**, the driver preset the variable at *pdwVersionLength* to 0, and the framework set the variable at *pdwVersionLength* to the number of characters that are required for the string.

**RetrieveVersionString** returns HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER) to indicate that the supplied buffer is non-**NULL** and did not contain enough space to hold the version. The framework sets the variable at *pdwVersionLength* to the number of characters that are required for the string.

**RetrieveVersionString** might also return other HRESULT values.