# DXGKCB_EVAL_ACPI_METHOD callback function

## Description

The **DxgkCbEvalAcpiMethod** function evaluates a specified ACPI method on a display adapter or on a child device of a display adapter.

## Parameters

### `DeviceHandle` [in]

A handle that represents a display adapter. The display miniport driver previously obtained this handle in the **DeviceHandle** member of the [DXGKRNL_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

### `DeviceUid` [in]

The unique identifier for the ACPI device on which the method will be evaluated. If the ACPI device is a child of the display adapter, this is the **ChildUid** member of the [DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor) structure that the display miniport driver filled in during [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations). If the ACPI device is the display adapter itself, this parameter must be set to DISPLAY_ADAPTER_HW_ID.

### `AcpiInputBuffer` [in]

A pointer to an [ACPI_EVAL_INPUT_BUFFER_COMPLEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_input_buffer_complex_v1) structure (defined in *Acpiioct.h*) allocated and filled in by the display miniport driver. The structure contains the arguments that are required by the ACPI method. See the following Remarks section for more information.

### `AcpiInputSize` [in]

The total size, in bytes, of the buffer pointed to by *AcpiInputBuffer*.

### `AcpiOutputBuffer` [out]

A pointer to an ACPI_EVAL_OUTPUT_BUFFER structure (defined in *Acpiioct.h*) that receives the return value of the ACPI method. This parameter can be **NULL**.

### `AcpiOutputSize` [in]

The total size, in bytes, of the buffer pointed to by *AcpiOutputBuffer*.

## Return value

**DxgkCbEvalAcpiMethod** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

To evaluate ACPI methods on an ACPI device, the device itself must be in the ACPI namespace. In addition, the display miniport driver must have set the lower 16 bits of the **ChildUid** value for any ACPI child devices that the display miniport driver reports to the identifier that ACPI reported.

Before it returns, **DxgkCbEvalAcpiMethod** resets the **Signature** member of the [ACPI_EVAL_INPUT_BUFFER_COMPLEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_input_buffer_complex_v1) structure to ACPI_EVAL_INPUT_BUFFER_COMPLEX_SIGNATURE. In Windows Vista with Service Pack 1 (SP1), Windows Server 2008, and later versions of the Windows operating systems, if the display miniport driver has child devices, it should set **Signature** to DXGK_ACPI_PASS_ARGS_TO_CHILDREN before it makes any call to **DxgkCbEvalAcpiMethod**.

**Note** The Microsoft DirectX graphics kernel subsystem cannot evaluate ACPI methods that are outside of the device's namespace.

**Note** Display miniport drivers can use **DxgkCbEvalAcpiMethod** only for lead-link graphics adapters.

#### Examples

The following code example shows how to evaluate an ACPI method.

```cpp
if (HwDeviceExtension->AcpiChildren != NULL) {
    ULONG ChildIndex;
    PACPI_METHOD_ARGUMENT AcpiChildrenArray =
 &(((PACPI_EVAL_OUTPUT_BUFFER)HwDeviceExtension->AcpiChildren)
   ->Argument[0]);
   ULONG ChildCount = ((PACPI_EVAL_OUTPUT_BUFFER)
   (HwDeviceExtension->AcpiChildren))->Count;
  ULONG ChildUid;
  ACPI_EVAL_INPUT_BUFFER_COMPLEX AcpiInputBuffer = {'\0'};
   ACPI_EVAL_OUTPUT_BUFFER AcpiOutputBuffer;
    pDesiredStatus = ExAllocatePoolWithTag(PagedPool,
 sizeof(DESIRED_CHILD_STATUS) * ChildCount,
 ATI_TAG);

  if (pDesiredStatus == NULL) {
     Status = STATUS_NO_MEMORY;
        goto cleanup;
  }

 RtlZeroMemory(pDesiredStatus, sizeof(DESIRED_CHILD_STATUS) * ChildCount);

 for (ChildIndex = 0; ChildIndex < ChildCount; ChildIndex++) {
 // If not a video output child, go to the next child.
 if (AcpiChildrenArray[ChildIndex].Argument
   & ACPI_NON_VIDEO_OUTPUT_DEVICE) {
   continue;
      }
      // A video output child so the ChildUid is the VidPnTargetId.
       ChildUid = (AcpiChildrenArray[ChildIndex].Argument
   & ACPI_HARDWARE_ID) | HW_ID_DISPLAY_CHILD;

      // Query ACPI for the required state.
      //
  // Beginning with Windows Vista SP1 and Windows Server 2008,
  // use DXGK_ACPI_PASS_ARGS_TO_CHILDREN.

  #if (NTDDI_VERSION >= NTDDI_WIN6SP1)
   AcpiInputBuffer.Signature =
   DXGK_ACPI_PASS_ARGS_TO_CHILDREN;
     #else
    AcpiInputBuffer.Signature =
   ACPI_EVAL_INPUT_BUFFER_COMPLEX_SIGNATURE;
       #endif

     AcpiInputBuffer.MethodNameAsUlong =
   ACPI_METHOD_OUTPUT_DGS;
     Status = DxgkCbEvalAcpiMethod(HwDeviceExtension->DeviceHandle,
         ChildUid,
         &AcpiInputBuffer,
         sizeof(ACPI_EVAL_INPUT_BUFFER_COMPLEX),
         &AcpiOutputBuffer,
         sizeof(ACPI_EVAL_OUTPUT_BUFFER));
     if (!NT_SUCCESS(Status)) {
         // Something really wrong
         goto cleanup;
     }
      // Determine what the new VidPn should be and
      // allow RecommendFunctionalVidPn to return it.
      // AcpiOutputBuffer.Argument[0].Argument == 1 indicates active
       // AcpiOutputBuffer.Argument[0].Argument == 0
       // indicates not active
       pDesiredStatus[ChildIndex].bActive =
   (AcpiOutputBuffer.Argument[0].Argument == 1) ? TRUE : FALSE;
      // Always use the first source because this is a keyboard shortcut.
      pDesiredStatus[ChildIndex].ulSourceId = 0;
      pDesiredStatus[ChildIndex].ulTargetId = ChildUid;
  }

 Status = InvalidateVidPnForHotKey(HwDeviceExtension, pDesiredStatus);
}
```

## See also

[ACPI_EVAL_INPUT_BUFFER_COMPLEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_input_buffer_complex_v1)

[DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor)

[DxgkDdiNotifyAcpiEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_notify_acpi_event)

[DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)