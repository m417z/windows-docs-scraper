# DeleteFont macro

## Syntax

```cpp
BOOL DeleteFont(
    HFONT hfont
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If **DeleteFont** succeeds, the return value is nonzero. If the specified handle is not valid or is currently selected into a Device Context, the return value is zero.

## Description

The **DeleteFont** macro deletes a font object, freeing all system resources associated with the font object.

## Parameters

### `hfont`

A handle to the font object.

## Remarks

After the font object is deleted, the specified handle is no longer valid.

The **DeleteFont** macro is equivalent to calling [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) as follows:

``` syntax

   DeleteObject((HGDIOBJ)(HFONT)(hfont))

```

## See also

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[SelectFont](https://learn.microsoft.com/windows/desktop/api/windowsx/nf-windowsx-selectfont)