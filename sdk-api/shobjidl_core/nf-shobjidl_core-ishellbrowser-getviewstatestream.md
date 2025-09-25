# IShellBrowser::GetViewStateStream

## Description

Gets an
**IStream** interface that can be used for storage of view-specific state information.

## Parameters

### `grfMode`

Type: **DWORD**

Read/write access of the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface. This may be one of the following values.

#### STGM_READ

Requests an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) suitable for reading.

#### STGM_WRITE

Requests an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) suitable for writing.

#### STGM_READWRITE

Requests an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) suitable for reading and writing.

### `ppStrm`

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)****

The address that receives the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface pointer.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error value otherwise.

## Remarks

This method is used to save and restore the persistent state for a view (the icon positions, the column widths, and the current scroll position, for example).

### Notes to Calling Applications

Use **GetViewStateStream** when the view is being created to read in the saved view state and also when the view is being closed to save any changes to the view state. Typically, the view calls this method with **STGM_READ** when creating a view window and with **STGM_WRITE** when the [SaveViewState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview-saveviewstate) method of its [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) interface is called.

### Notes to Implementers

Each Shell view should have its own view stream. Windows Explorer implements a most recently used (MRU) list of view streams that are stored on a per-user basis in the registry.

See also [IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser)