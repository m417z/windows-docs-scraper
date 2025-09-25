# PathToRegion function

## Description

The **PathToRegion** function creates a region from the path that is selected into the specified device context. The resulting region uses device coordinates.

## Parameters

### `hdc` [in]

Handle to a device context that contains a closed path.

## Return value

If the function succeeds, the return value identifies a valid region.

If the function fails, the return value is zero.

## Remarks

When you no longer need the **HRGN** object call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

The device context identified by the *hdc* parameter must contain a closed path.

After **PathToRegion** converts a path into a region, the system discards the closed path from the specified device context.