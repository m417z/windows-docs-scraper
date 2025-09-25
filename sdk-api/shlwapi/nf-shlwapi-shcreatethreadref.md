# SHCreateThreadRef function

## Description

Creates a per-thread reference to a Component Object Model (COM) object.

## Parameters

### `pcRef` [in]

Type: **LONG***

A pointer to a value, usually a local variable in the thread's [ThreadProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms686736(v=vs.85)), that is used by the interface in *ppunk* as a reference counter.

### `ppunk` [out]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

The address of a pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. If successful, this parameter holds the thread's **IUnknown** pointer on return. Your application is responsible for freeing the pointer when it is finished.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

See [Managing Thread References](https://learn.microsoft.com/windows/desktop/shell/managing-thread-references) for more details on using the Shlwapi thread APIs.

## See also

[SHCreateThread](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shcreatethread)

[SHGetThreadRef](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shgetthreadref)

[SHReleaseThreadRef](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shreleasethreadref)

[SHSetThreadRef](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shsetthreadref)