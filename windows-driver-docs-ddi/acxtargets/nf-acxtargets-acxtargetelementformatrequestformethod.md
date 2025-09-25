## Description

The **AcxTargetElementFormatRequestForMethod** function formats a WDFREQUEST as an ACX method request to be used on specified element target.

## Parameters

### `TargetElement`

An ACXTARGETELEMENT handle. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Request`

A WDFREQUEST handle described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects). For general information about WDF requests, see [Creating Framework Request Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-framework-request-objects).

### `Params`

An initialized [ACX_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ns-acxrequest-acx_request_parameters) structure that is used to store method request parameter information.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

A WDFREQUEST is a driver created I/O requests. Framework-based drivers process each I/O request by calling framework request object methods. For more information, see [Framework Request Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-request-objects).

### Example

This sample code shows the use of the AcxTargetElementFormatRequestForMethod.

```cpp

    {
        ACXTARGETELEMENT targetElement          = NULL;
        ULONG            targetElementId        = 0;
        ULONG            targetElementsCount    = AcxTargetCircuitGetElementsCount(TargetCircuit);
        arg     = elementArg;
        result  = 0;

        targetElement = AcxTargetCircuitGetTargetElement(TargetCircuit, targetElementId);

        ACX_REQUEST_PARAMETERS_INIT_METHOD(
            &params,
            KSMETHODSETID_AcxTestMethod,
            KSMETHOD_ACXELEMENT_TEST_IN2OUT,
            AcxMethodVerbSend,
            AcxItemTypeElement,
            targetElementId,
            &arg, sizeof(arg),      // Value & size
            &result, sizeof(result) // Control & size
            );

        //
        // Format a WDF request as an ACX method request for the ACX element target.
        //
        status = AcxTargetElementFormatRequestForMethod(targetElement, req, &params);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)