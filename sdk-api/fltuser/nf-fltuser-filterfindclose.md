# FilterFindClose function

## Description

The **FilterFindClose** function closes the specified minifilter search handle. The [FilterFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindfirst) and [FilterFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindnext) functions use this search handle to locate minifilters.

## Parameters

### `hFilterFind` [in]

Minifilter search handle to close. This handle must have been opened by a previous call to [FilterFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindfirst).

## Return value

**FilterFindClose** returns S_OK if successful. Otherwise, it returns an error value.

## Remarks

After the **FilterFindClose** function is called, the minifilter search handle specified by the *hFilterFind* parameter cannot be used in subsequent calls to [FilterFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindnext) or **FilterFindClose**.

Use **FilterFindClose** to close handles returned by calls to [FilterFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindfirst). Use [FilterClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterclose) to close handles returned by calls to [FilterCreate](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtercreate).

## See also

[FilterClose](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterclose)

[FilterCreate](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filtercreate)

[FilterFindFirst](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindfirst)

[FilterFindNext](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterfindnext)