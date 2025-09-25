# MagShowSystemCursor function

## Description

Shows or hides the system cursor.

## Parameters

### `fShowCursor` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

TRUE to show the system cursor, or FALSE to hide it.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns TRUE if successful, or FALSE otherwise.

## Remarks

This function does not associate a reference count with the visibility state of the system cursor. Instead, the specified visibility state takes effect immediately, regardless of any previous calls to **MagShowSystemCursor**.

The system cursor is always magnified when it is shown while the full-screen magnifier is active.

When used with a magnifier control, calls to **MagShowSystemCursor** have no effect on the magnified system cursor. The visibility of the magnified system cursor depends on whether the magnifier control has the [MS_SHOWMAGNIFIEDCURSOR](https://learn.microsoft.com/previous-versions/windows/desktop/magapi/magapi-magnifier-styles) style. If it has this style, the magnifier control displays the magnified system cursor, along with the magnified screen content, whenever the system cursor enters the source rectangle.

#### Examples

The following example uses the **MagShowSystemCursor** function to set the visibility state of the system cursor.

```cpp
// Description:
//   Show or hide the system cursor.
//
// Parameters:
//   fShow - TRUE to show the system cursor, FALSE to hide it.
//
BOOL ShowSystemCursor(BOOL fShow)
{
    BOOL fResult = MagShowSystemCursor(fShow);

    return fResult;
}

```