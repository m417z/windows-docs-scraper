# FilterVolumeInstanceFindClose function

## Description

The **FilterVolumeInstanceFindClose** function closes the specified volume instance search handle. [FilterVolumeInstanceFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindfirst) and [FilterVolumeInstanceFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindnext) use this search handle to locate instances on a volume.

## Parameters

### `hVolumeInstanceFind` [in]

Volume instance search handle to close. This handle must have been opened by a previous call to [FilterVolumeInstanceFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindfirst).

## Return value

**FilterVolumeInstanceFindClose** returns S_OK if successful. Otherwise, it returns an error value.

## Remarks

After the **FilterVolumeInstanceFindClose** function is called, the handle specified by the *hVolumeInstanceFind* parameter cannot be used in subsequent calls to [FilterVolumeInstanceFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindnext) or **FilterVolumeInstanceFindClose**.

## See also

[FilterVolumeInstanceFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindfirst)

[FilterVolumeInstanceFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtervolumeinstancefindnext)