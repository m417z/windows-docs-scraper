# ReuseDDElParam function

## Description

Enables an application to reuse a packed Dynamic Data Exchange (DDE) *lParam* parameter, rather than allocating a new packed
*lParam*. Using this function reduces reallocations for applications that pass packed DDE messages.

## Parameters

### `lParam` [in]

Type: **LPARAM**

The
*lParam* parameter of the posted DDE message being reused.

### `msgIn` [in]

Type: **UINT**

The identifier of the received DDE message.

### `msgOut` [in]

Type: **UINT**

The identifier of the DDE message to be posted. The DDE message will reuse the packed
*lParam* parameter.

### `uiLo` [in]

Type: **UINT_PTR**

The value to be packed into the low-order word of the reused
*lParam* parameter.

### `uiHi` [in]

Type: **UINT_PTR**

The value to be packed into the high-order word of the reused
*lParam* parameter.

## Return value

Type: **LPARAM**

The return value is the new
*lParam* value.

## Remarks

The return value must be posted as the
*lParam* parameter of a DDE message; it must not be used for any other purpose. Once the return value is posted, the posting application need not perform any action to dispose of the
*lParam* parameter.

Use **ReuseDDElParam** instead of [FreeDDElParam](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-freeddelparam) if the
*lParam* parameter will be reused in a responding message. **ReuseDDElParam** returns the
*lParam* appropriate for reuse.

This function allocates or frees
*lParam* parameters as needed, depending on the packing requirements of the incoming and outgoing messages. This reduces reallocations in passing DDE messages.

## See also

[About Dynamic Data Exchange](https://learn.microsoft.com/windows/desktop/dataxchg/about-dynamic-data-exchange)

**Conceptual**

[FreeDDElParam](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-freeddelparam)

[PackDDElParam](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-packddelparam)

**Reference**

[UnpackDDElParam](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-unpackddelparam)