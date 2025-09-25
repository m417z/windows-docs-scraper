# EtwWriteString function

## Description

The **EventWriteString** function is a tracing function that you can use when no sophisticated data is required. This function is similar to a debug print statement.

## Parameters

### `RegHandle` [in]

A Pointer to the event provider registration handle, which is returned by the **EtwRegister** function if the event provider registration is successful.

### `Level` [in]

The level at which the event is active.

### `Keyword` [in]

The keyword for the event. A keyword is a bitmask that makes general statements about the category of the event or error. Because the keyword is a bitmask, you can apply more than one keyword to a single event. You can define the keywords and bit positions, or you can use Windows-standard keywords, or you can use combination of your own keywords and the Windows keywords.

### `ActivityId` [in, optional]

The identifier that indicates the activity associated with the event. The *ActivityId* provides a way to group related events and is used in end-to-end tracing. This identifier is optional and can be **NULL**.

### `String` [in]

A null-terminated string (WCHAR).

## Return value

The function returns STATUS_SUCCESS if the event is published successfully.

## Remarks

Because the string produced by **EventWriteString** function is not localizable, this function is not recommended for use in production code. This function should not be used to log highly visible events.

You can call **EtwWriteString** at any IRQL. However, when IRQL is greater than APC_LEVEL, any data passed to the **EtwWrite**, [EtwWriteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwwriteex), **EtwWriteString**, and **EtwWriteTransfer** functions must not be pageable. That is, any kernel-mode routine that is running at IRQL greater than APC_LEVEL cannot access pageable memory. Data passed to the **EtwWrite**, **EtwWriteEx**, **EtwWriteString**, and **EtwWriteTransfer** functions must reside in system-space memory, regardless of what the IRQL is.

## See also

[EtwWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwwrite)

[EtwWriteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwwriteex)

[EtwWriteTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etwwritetransfer)