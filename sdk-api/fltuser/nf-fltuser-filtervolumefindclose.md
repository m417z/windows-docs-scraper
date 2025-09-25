# FilterVolumeFindClose function

## Description

The **FilterVolumeFindClose** function closes the specified volume search handle. [FilterVolumeFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindfirst) and [FilterVolumeFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindnext) use this search handle to locate volumes.

## Parameters

### `hVolumeFind` [in]

Volume search handle to close. This handle must have been previously opened by [FilterVolumeFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindfirst).

## Return value

**FilterVolumeFindClose** returns S_OK if successful. Otherwise, it returns an error value.

## Remarks

After the **FilterVolumeFindClose** function is called, the handle specified by the *hVolumeFind* parameter cannot be used in subsequent calls to [FilterVolumeFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindnext) or **FilterVolumeFindClose**.

## See also

[FilterVolumeFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindfirst)

[FilterVolumeFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumefindnext)