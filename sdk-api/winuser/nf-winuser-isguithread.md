# IsGUIThread function

## Description

Determines whether the calling thread is already a GUI thread. It can also optionally convert the thread to a GUI thread.

## Parameters

### `bConvert` [in]

Type: **BOOL**

If **TRUE** and the thread is not a GUI thread, convert the thread to a GUI thread.

## Return value

Type: **BOOL**

The function returns a nonzero value in the following situations:

* If the calling thread is already a GUI thread.
* If *bConvert* is **TRUE** and the function successfully converts the thread to a GUI thread.

Otherwise, the function returns zero.

If *bConvert* is **TRUE** and the function cannot successfully convert the thread to a GUI thread, **IsGUIThread** returns **ERROR_NOT_ENOUGH_MEMORY**.

## See also

[Windows Overview](https://learn.microsoft.com/windows/desktop/winmsg/windows)