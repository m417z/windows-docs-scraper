# IQuickActivate::GetContentExtent

## Description

Gets the content extent of a control.

## Parameters

### `pSizel` [out]

A pointer to a structure that contains size of the content extent.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_FAIL.

## Remarks

The **SIZEL** structure is defined in Wtypes.h as follows.

``` syntax
typedef struct tagSIZEL
    {
    LONG cx;
    LONG cy;
    } 	SIZEL;

typedef struct tagSIZEL *PSIZEL;

typedef struct tagSIZEL *LPSIZEL;
```

## See also

[IQuickActivate](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iquickactivate)