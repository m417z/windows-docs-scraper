# ITracing::SetTraceLevel

## Description

The **SetTraceLevel** method sets the tracing level for an object. Every object in the WDTF object model should support the **SetTraceLevel** method

## Parameters

### `Level` [in]

The new [TTraceLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/) value for this object.

## Return value

**SetTraceLevel** returns a standard **HRESULT** value.

## Remarks

For more information about tracing levels, see [TTraceLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/) and [ITracer](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

Use the [Trace_Default](https://learn.microsoft.com/windows-hardware/drivers/ddi/) level to set the object back to the settings that are defined in the registry for the object's co-class.

Because the [IAction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nn-wdtf-iaction) interface inherits from the [ITracing](https://learn.microsoft.com/windows-hardware/drivers/ddi/) interface, all WDTF Actions will support **SetTraceLevel**. All of the [WDTF core interfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/) should also support this method.

The following code example demonstrates how to use the **SetTraceLevel** method.

**VBScript**

```
'
' Get DeviceManagement Action interface for the target
'
Set Action = CDROM.GetInterface("DeviceManagement")

If Err.number <> 0 Then
    WScript.Echo Space(4) & "Failed to get interface DeviceManagement. Error Number:" & Err.number
Else
    '
    ' Set the tracing level to HIGH
    '
    Action.SetTraceLevel(Trace3_High)
    If Err.number <> 0 Then
        WScript.Echo Space(4) & "Failed to set tracing level to 'High'. Error Number:" & Err.number
    End If

    '
    ' Disable the CD-ROM
    '
    WScript.Echo Space(4) & "Trying to disable device..."

    Action.Disable()

    If Err.number <> 0 Then
        WScript.Echo Space(4) & "Failed to disable the specified CDROM. Error     Number:" & Err.number & vbcrlf
    Else
        WScript.Echo Space(4) & "Specified CDROM successfully disabled." & vbcrlf
    End If
End If
```

**C++**

```
IDevMan* pDevMan;        // DeviceManagement Action interface

VARIANT vtEmpty;       // To be passed as a parameter to ITarget::GetInterface
VariantInit(&vtEmpty);

//
// Get DeviceManagement Action interface
//
hr = pCDROM->GetInterface(L"DeviceManagement", vtEmpty, vtEmpty, (IAction**)(&pDevMan));
if(FAILED(hr))
{
    _tprintf(_T("\n  Failed to get DeviceManagement Interface for specified CDROM Device. Error: 0x%x"), hr);
 goto Cleanup;
}

//
// Set the trace level to High
//
hr = pDevMan->SetTraceLevel(Trace3_High);
if(FAILED(hr))
{
    _tprintf(_T("\n  Failed to set tracing level to 'High'. Error: 0x%x"), hr);
}

//
// Disable the CD-ROM
//
_tprintf(_T("\n  Trying to disable device..."));

hr = pDevMan->Disable();
if(FAILED(hr))
{
    _tprintf(_T("\n  Failed to disable the specified CDROM. Error: 0x%x"), hr);
}
else
{
    _tprintf(_T("\n  Specified CDROM successfully disabled."));
}
```

## See also

[ITracer](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[ITracing](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[TTraceLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/)