# SHSetThreadRef function

## Description

Stores a per-thread reference to a Component Object Model (COM) object. This allows the caller to control the thread's lifetime so that it can ensure that Windows won't shut down the thread before the caller is ready.

## Parameters

### `punk` [in, optional]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of the object for which you want to store a reference. This value can be **NULL**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Use [SHGetThreadRef](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shgetthreadref) to retrieve the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer.

## See also

[SHCreateThread](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shcreatethread)

[SHCreateThreadRef](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shcreatethreadref)

[SHGetThreadRef](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shgetthreadref)

[SHReleaseThreadRef](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shreleasethreadref)