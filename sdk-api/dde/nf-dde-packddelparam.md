# PackDDElParam function

## Description

Packs a Dynamic Data Exchange (DDE) *lParam* value into an internal structure used for sharing DDE data between processes.

## Parameters

### `msg` [in]

Type: **UINT**

The DDE message to be posted.

### `uiLo` [in]

Type: **UINT_PTR**

A value that corresponds to the 16-bit Windows low-order word of an *lParam* parameter for the DDE message being posted.

### `uiHi` [in]

Type: **UINT_PTR**

A value that corresponds to the 16-bit Windows high-order word of an *lParam* parameter for the DDE message being posted.

## Return value

Type: **LPARAM**

The return value is the *lParam* value.

## Remarks

The return value must be posted as the *lParam* parameter of a DDE message; it must not be used for any other purpose. After the application posts a return value, it need not perform any action to dispose of the *lParam* parameter.

An application should call this function only for posted DDE messages.

## See also

[About Dynamic Data Exchange](https://learn.microsoft.com/windows/desktop/dataxchg/about-dynamic-data-exchange)

**Conceptual**

[FreeDDElParam](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-freeddelparam)

**Reference**

[ReuseDDElParam](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-reuseddelparam)

[UnpackDDElParam](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-unpackddelparam)