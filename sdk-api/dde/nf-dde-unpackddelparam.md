# UnpackDDElParam function

## Description

Unpacks a Dynamic Data Exchange (DDE)*lParam* value received from a posted DDE message.

## Parameters

### `msg` [in]

Type: **UINT**

The posted DDE message.

### `lParam` [in]

Type: **LPARAM**

The
*lParam* parameter of the posted DDE message that was received. The application must free the memory object specified by the
*lParam* parameter by calling the [FreeDDElParam](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-freeddelparam) function.

### `puiLo` [out]

Type: **PUINT_PTR**

A pointer to a variable that receives the low-order word of
*lParam*.

### `puiHi` [out]

Type: **PUINT_PTR**

A pointer to a variable that receives the high-order word of
*lParam*.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

[PackDDElParam](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-packddelparam) eases the porting of 16-bit DDE applications to 32-bit DDE applications.

## See also

[About Dynamic Data Exchange](https://learn.microsoft.com/windows/desktop/dataxchg/about-dynamic-data-exchange)

**Conceptual**

[FreeDDElParam](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-freeddelparam)

[PackDDElParam](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-packddelparam)

**Reference**

[ReuseDDElParam](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-reuseddelparam)