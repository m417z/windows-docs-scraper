# FilterInstanceClose function

## Description

The **FilterInstanceClose** function closes a minifilter instance handle opened by **FilterInstanceCreate**.

## Parameters

### `hInstance` [in]

Minifilter instance handle returned by a previous call to [FilterInstanceCreate](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancecreate).

## Return value

**FilterInstanceClose** returns S_OK if successful. Otherwise, it returns an error value.

## Remarks

After the **FilterInstanceClose** function is called, the minifilter instance handle specified by the *hFilterInstanceFind* parameter is no longer valid and cannot safely be used.

Use **FilterInstanceClose** to close handles returned by calls to [FilterInstanceCreate](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancecreate). Use [FilterInstanceFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancefindclose) to close handles returned by calls to [FilterInstanceFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancefindfirst).

## See also

[FilterInstanceCreate](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancecreate)

[FilterInstanceFindClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancefindclose)

[FilterInstanceFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancefindfirst)