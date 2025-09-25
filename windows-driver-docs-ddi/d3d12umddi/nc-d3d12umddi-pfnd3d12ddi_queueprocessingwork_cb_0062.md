# PFND3D12DDI_QUEUEPROCESSINGWORK_CB_0062 callback function

## Description

*PfnQueueProcessingWorkCb* is provided by the runtime and called by user mode drivers to register and queue work items.

The runtime is responsible for managing threads, either directly, or through a Thread Pool. The UMD will not have any control over which thread the work is processed on. Work will be processed in the order it was received. *PfnQueueProcessingWorkCb* may be called from multiple threads concurrently and is thread safe (runtime will serialize).

## Parameters

### `hRTDevice` [in]

The handle of the device for the driver to use when it calls back into the runtime.

### `pfnCallback` [in]

Pointer to a [PFND3D12DDI_UMD_CALLBACK_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_umd_callback_method) callback that is called from the thread where work is being performed.

### `pfnCancel` [in, opt]

Pointer to a [PFND3D12DDI_UMD_CALLBACK_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_umd_callback_method) callback that is called if the device is destroyed before *pfnCallback* has executed.

### `pContext` [in, opt]

Pointer to a device context that is passed to *pfnCallback* or *pfnCancel*.

## Return value

Returns HRESULT.

## Prototype

```
//Declaration

PFND3D12DDI_QUEUEPROCESSINGWORK_CB_0062 Pfnd3d12ddiQueueprocessingworkCb0062;

// Definition

HRESULT Pfnd3d12ddiQueueprocessingworkCb0062
(
	D3D12DDI_HRTDEVICE hRTDevice
	PFND3D12DDI_UMD_CALLBACK_METHOD pfnCallback
	PFND3D12DDI_UMD_CALLBACK_METHOD pfnCancel
	 void *pContext
)
{...}

```

## Remarks

## See also