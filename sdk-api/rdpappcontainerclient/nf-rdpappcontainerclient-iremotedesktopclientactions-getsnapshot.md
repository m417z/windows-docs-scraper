# IRemoteDesktopClientActions::GetSnapshot

## Description

Causes a snapshot of the Remote Desktop Protocol (RDP) app container client's in-session desktop to be taken.

## Parameters

### `snapshotEncoding` [in]

Specifies the encoding type for the snapshot.

### `snapshotFormat` [in]

Specifies the data format type for the snapshot

### `snapshotWidth` [in]

The width, in pixels, of the snapshot.

### `snapshotHeight` [in]

The height, in pixels, of the snapshot.

### `snapshotData` [out, retval]

On return points to the snapshot.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRemoteDesktopClientActions](https://learn.microsoft.com/windows/desktop/api/rdpappcontainerclient/nn-rdpappcontainerclient-iremotedesktopclientactions)