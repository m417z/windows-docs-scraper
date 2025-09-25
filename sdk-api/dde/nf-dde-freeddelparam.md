# FreeDDElParam function

## Description

Frees the memory specified by the
*lParam* parameter of a posted Dynamic Data Exchange (DDE) message. An application receiving a posted DDE message should call this function after it has used the [UnpackDDElParam](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-unpackddelparam) function to unpack the
*lParam* value.

## Parameters

### `msg` [in]

Type: **UINT**

The posted DDE message.

### `lParam` [in]

Type: **LPARAM**

The
*lParam* parameter of the posted DDE message.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

An application should call this function only for posted DDE messages.

This function frees the memory specified by the
*lParam* parameter. It does not free the contents of
*lParam*.

## See also

[About Dynamic Data Exchange](https://learn.microsoft.com/windows/desktop/dataxchg/about-dynamic-data-exchange)

**Conceptual**

[PackDDElParam](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-packddelparam)

**Reference**

[ReuseDDElParam](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-reuseddelparam)

[UnpackDDElParam](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-unpackddelparam)