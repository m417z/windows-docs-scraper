# ID3D10SwitchToRef::GetUseRef

## Description

Get a boolean value that indicates the type of device being used.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if the device is a software device, **FALSE** if the device is a hardware device. See remarks.

## Remarks

A hardware device is commonly referred to as a HAL device, which stands for a hardware accelerated device. This means that the pipeline is rendering all of the pipeline commands in hardware, using the GPU. Operating the pipeline with a HAL device gives the best performance generally, but it can be more difficult to debug since resources exist on the GPU instead of the CPU.

A software device implements rendering in software using the CPU with no hardware acceleration. A software device is commonly referred to as a reference device or REF device. Because a REF device implements rendering on the CPU, it is generally slower, but is easier to debug since it allows access to resources.

## See also

[ID3D10SwitchToRef Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10switchtoref)