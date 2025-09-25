# FilterInstanceFindClose function

## Description

The **FilterInstanceFindClose** function closes the specified minifilter instance search handle. The [FilterInstanceFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancefindfirst) and [FilterInstanceFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancefindnext) functions use this search handle to locate instances of a minifilter.

## Parameters

### `hFilterInstanceFind` [in]

Minifilter instance search handle to close. This handle must have been opened by a previous call to [FilterInstanceFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancefindfirst).

## Return value

**FilterInstanceFindClose** returns S_OK if successful. Otherwise, it returns an error value.

## Remarks

After the **FilterInstanceFindClose** function is called, the minifilter instance search handle specified by the *hFilterInstanceFind* parameter cannot be used in subsequent calls to [FilterInstanceFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancefindfirst) or **FilterInstanceFindClose**.

Use **FilterInstanceFindClose** to close handles returned by calls to [FilterInstanceFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancefindfirst). Use [FilterInstanceClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstanceclose) to close handles returned by calls to [FilterInstanceCreate](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancecreate).

## See also

[FilterInstanceClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstanceclose)

[FilterInstanceCreate](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancecreate)

[FilterInstanceFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancefindfirst)

[FilterInstanceFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterinstancefindnext)