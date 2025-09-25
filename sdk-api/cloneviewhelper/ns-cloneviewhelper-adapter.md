# Adapter structure

## Description

The Adapter structure describes a graphics adapter.

## Members

### `AdapterName`

A single wide-character string that holds the name of the graphics adapter.

### `numSources`

The number of video present sources in the array that the **sources** member specifies.

### `sources`

An array of [Sources](https://learn.microsoft.com/windows/desktop/api/cloneviewhelper/ns-cloneviewhelper-sources) structures that specify a list of Video Present Network (VidPN) topologies.

## See also

[IViewHelper::SetConfiguration](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568176(v=vs.85))

[Sources](https://learn.microsoft.com/windows/desktop/api/cloneviewhelper/ns-cloneviewhelper-sources)