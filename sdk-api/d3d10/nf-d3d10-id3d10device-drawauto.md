# ID3D10Device::DrawAuto

## Description

Draw geometry of an unknown size that was created by the geometry shader stage. See remarks.

## Remarks

A [draw API](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage-getting-started) submits work to the rendering pipeline.

After data has been streamed out to [SO stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-stream-stage) buffers, those buffers can be again bound to the Input Assembler stage at input slot 0 and DrawAuto will draw them without the application needing to know the amount of data that was written to the buffers. A measurement of the amount of data written to the SO stage buffers is maintained internally when the data is streamed out. This means that the CPU does not need to fetch the measurement before re-binding the data that was streamed as input data. Although this amount is tracked internally, it is still the responsibility of applications to use input layouts to describe the format of the data in the SO stage buffers so that the layouts are available when the buffers are again bound to the input assembler.

The following diagram shows the DrawAuto process.

![Diagram of DrawAuto as data moves through several stages to a buffer and then back to the Input Assembler stage](https://learn.microsoft.com/windows/win32/api/d3d10/images/d3d10_pipeline_stages_drawauto.png)

Calling DrawAuto does not change the state of the streaming-output buffers that were bound again as inputs.

DrawAuto only works when drawing with one input buffer bound as an input to the IA stage at slot 0. Applications must create the SO buffer resource with both binding flags, [D3D10_BIND_VERTEX_BUFFER](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_bind_flag) and **D3D10_BIND_STREAM_OUTPUT**.

This API does not support indexing or instancing.

If an application needs to retrieve the size of the streaming-output buffer, it can query for statistics on streaming output by using [D3D10_QUERY_SO_STATISTICS](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_query).

Example of using DrawAuto can be found in the [ParticlesGS Sample](https://msdn.microsoft.com/library/Ee416421(v=VS.85).aspx) and [PipesGS Sample](https://msdn.microsoft.com/library/Ee416423(v=VS.85).aspx).

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)