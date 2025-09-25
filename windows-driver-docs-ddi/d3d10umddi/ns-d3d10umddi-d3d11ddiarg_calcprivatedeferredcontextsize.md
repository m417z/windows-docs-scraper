# D3D11DDIARG_CALCPRIVATEDEFERREDCONTEXTSIZE structure

## Description

The D3D11DDIARG_CALCPRIVATEDEFERREDCONTEXTSIZE structure describes the parameters that the user-mode display driver uses to calculate the size of a memory block that the driver requires to store frequently-accessed data.

## Members

### `Flags` [in]

A valid bitwise OR of flag values that identify how to create a rendering device. The Direct3D runtime supports the following flags:

#### D3D10DDI_CREATEDEVICE_FLAG_DISABLE_EXTRA_THREAD_CREATION (0x1)

If this flag is set, the user-mode display driver should not run multiple threads simultaneously when it processes calls to its functions from the Direct3D runtime. A driver can typically start and run multiple threads to process operations faster, unless D3D10DDI_CREATEDEVICE_FLAG_DISABLE_EXTRA_THREAD_CREATION is set.

#### D3D11DDI_CREATEDEVICE_FLAG_SINGLETHREADED (0x10)

This flag informs the user-mode display driver that the application is single threaded. The Direct3D version 11 runtime allows multiple application threads to enter the driver if the driver allows this mode of operation. However, not all applications can run multiple threads. If this flag is set, the driver will not expect multiple threads to enter it and run simultaneously. The driver can avoid synchronization if this flag is present.

#### The flag that is set in the 0xE mask of the Flags member

This flag represents the level of 3-D pipeline that the driver should support for the display device. The driver uses the following constant and macros to extract one of the values from the [D3D11DDI_3DPIPELINELEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11ddi_3dpipelinelevel) enumeration that represent the 3-D pipeline level to support. The value in the **Flags** member is formatted like the **Caps** member of the [D3D11DDI_3DPIPELINESUPPORT_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_3dpipelinesupport_caps) structure.

```cpp
#define D3D11DDI_CREATEDEVICE_FLAG_3DPIPELINESUPPORT_SHIFT (0x1)
#define D3D11DDI_CREATEDEVICE_FLAG_3DPIPELINESUPPORT_MASK (0x7 << D3D11DDI_CREATEDEVICE_FLAG_3DPIPELINESUPPORT_SHIFT)
#define D3D11DDI_EXTRACT_3DPIPELINELEVEL_FROM_FLAGS( Flags ) \
    ((D3D11DDI_3DPIPELINELEVEL)(((Flags) & D3D11DDI_CREATEDEVICE_FLAG_3DPIPELINESUPPORT_MASK) >> \
    D3D11DDI_CREATEDEVICE_FLAG_3DPIPELINESUPPORT_SHIFT))
```

## See also

[D3D11DDI_3DPIPELINELEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11ddi_3dpipelinelevel)

[D3D11DDI_3DPIPELINESUPPORT_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_3dpipelinesupport_caps)