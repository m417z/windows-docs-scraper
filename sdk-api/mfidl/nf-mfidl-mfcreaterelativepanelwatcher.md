## Description

Creates a new instance of the **IMFRelativePanelWatcher** interface, which monitors the panel associated with the provided display monitor, so that the app receives notifications when the relative location of the panel changes.

## Parameters

### `videoDeviceId`

A string containing the symbolic link name of the video capture device.

### `displayMonitorDeviceId`

A string containing the symbolic link name of the display monitor device.

### `ppRelativePanelWatcher`

A pointer to an **IMFRelativePanelWatcher** interface representing the watcher.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
|--------------|------------------------|
|S_OK | The function succeeded.|

## Remarks

## See also