# D3D10DDI_QUERY enumeration

## Description

The D3D10DDI_QUERY enumeration type contains values that identify a query type.

## Constants

### `D3D10DDI_QUERY_EVENT`

This query type provides a synchronization primitive that many of the following query types mimic to deal with the asynchronous nature of the graphics processing unit (GPU). An issued D3D10DDI_QUERY_EVENT becomes signaled after the GPU is finished with all of the previously issued commands, generally from the backend of the graphics pipeline. The data that the driver associates with this query type is a BOOL. However, the BOOL value is redundant because whenever a D3D10DDI_QUERY_EVENT query is signaled, the value of the BOOL is always **TRUE**. The driver should always send back the BOOL data value of **TRUE** when signaling the D3D10DDI_QUERY_EVENT.

### `D3D10DDI_QUERY_OCCLUSION`

The statistic data that the driver associates with this query type is a UINT64. This statistic data contains the number of multisamples that passed depth and stencil testing, also known as "visible" multisamples, for all primitives since the creation of the device context. If the render target is not multisampled, the counter is incremented by the number of whole pixels that are visible. The counter should wrap around when it overflows.

> [!NOTE]
> The Direct3D runtime can call the driver's [**QueryGetData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querygetdata) function at any time to request this statistic data. Therefore, it must be continually calculated accurately.

Only the difference between two independent statistic requests will provide meaningful information. The driver should calculate the difference between the statistic data that it receives when a call to its [**QueryBegin**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querybegin) function occurs and the statistic data that it receives when a call to its [**QueryEnd**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_queryend) function occurs.

For the purposes of calculating visible multisamples, disabled depth tests or stencil tests should behave as if the multisamples "pass" the disabled test. This produces equivalent results to when the test units were enabled with the test function set to "always". In addition, these values should be tabulated as normal even if there are no render targets bound. Because the depth and stencil tests logically occur in the output-merger stage of the pipeline, pixels that are discarded during pixel-shader execution do not increment the occlusion counter. Discarded pixels logically do not even reach the output merger. There are pipeline configurations where the only effective results that are produced from the pipeline are the tabulation of the occlusion counter.

### `D3D10DDI_QUERY_TIMESTAMP`

The data that the driver associates with this query type is a UINT64. The TIMESTAMP query type is used similarly to the D3D10DDI_QUERY_EVENT query type because the TIMESTAMP query type also provides a type of synchronization primitive. Like D3D10DDI_QUERY_EVENT, TIMESTAMP should become signaled when the GPU is finished with all the previously issued commands. However, TIMESTAMP differs from D3D10DDI_QUERY_EVENT by returning a 64-bit timestamp value. This 64-bit timestamp value should be sampled from a GPU counter, which increments at a consistent frequency. The timestamp value should be sampled at the instant that the GPU is finished with all the previously issued commands. The GPU is not required to ensure that all caches are flushed to memory to determine that work is complete. This is so that satisfying multiple high-frequency TIMESTAMP query types does not heavily disturb the pipeline. However, the CPU should monitor well-defined memory write-ordering between itself and the GPU, especially when D3D10DDI_QUERY_EVENT is supported. If the CPU were to determine that the GPU wrote a certain value (especially a fence value), the CPU would determine that all previous memory writes that were issued prior to the fence write should be flushed to memory and able to be seen immediately by the CPU. The type of flush that might be required to get data out of GPU caches and into CPU accessible memory should not need to be done every TIMESTAMP but probably more at the end of every command buffer.

The frequency of the timestamp counter is provided within the context of a D3D10DDI_QUERY_TIMESTAMPDISJOINT query type. The frequency of this counter should be greater than 10 MHz and resistant to high-frequency dynamic throttling of the GPU. The timestamp counter should be global. Therefore, the timestamp counter is not required to take into account the GPU time slicing of contexts.

The initial value of the timestamp counter is unspecified. Therefore, the absolute value of the timestamp counter is generally meaningless by itself. However, the relative value that is generated from the difference of two absolute values quantifies an elapsed amount of time. The difference of two timestamp values is only accurate when the two TIMESTAMP queries are bracketed within a D3D10DDI_QUERY_TIMESTAMPDISJOINT range and when the query-disjoint value of the D3D10DDI_QUERY_TIMESTAMPDISJOINT query returns **FALSE**.

### `D3D10DDI_QUERY_TIMESTAMPDISJOINT`

The data that the driver associates with this query type is a [**D3D10_DDI_QUERY_DATA_TIMESTAMP_DISJOINT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_timestamp_disjoint) structure. TIMESTAMPDISJOINT allows an application to define a bracketing to not only request the frequency of the TIMESTAMP clock but also to detect if that frequency was consistent throughout the entire bracketed range of graphics commands. The **Disjoint** member of D3D10_DDI_QUERY_DATA_TIMESTAMP_DISJOINT contains a BOOL value that indicates when something caused the timestamp counter to become discontinuous or disjoint. A few examples of events that should trigger TIMESTAMPDISJOINT are a power down, throttling up and down due to laptop power saving events, an unplugged AC cord, and overheating. Such event occurrences should be rare enough during a steady graphics application execution state to be avoided by controlling the system execution environment. Note that if such events occur, they effectively reduce the usefulness of the TIMESTAMP functionality. TIMESTAMP queries after an event that would trigger a TIMESTAMPDISJOINT query are not expected to be meaningful compared to TIMESTAMP queries preceding such an event. The BOOL value in the **Disjoint** member is **TRUE** if the values from TIMESTAMP queries cannot be guaranteed to be continuous throughout the duration of the TIMESTAMPDISJOINT query. Otherwise, **Disjoint** should be **FALSE**. The value of the **Frequency** member of D3D10_DDI_QUERY_DATA_TIMESTAMP_DISJOINT should be equal to the frequency of the TIMESTAMP clock.

In addition, notifications of such throttling events is useful for performance monitoring, regression, and investigation tools, assuming the notifications result in performance differences in application execution.

### `D3D10DDI_QUERY_PIPELINESTATS`

See Remarks for details.

### `D3D10DDI_QUERY_OCCLUSIONPREDICATE`

The data that the driver associates with this query type is a BOOL. This predicate mirrors the specification for the OCCLUSION query. If the OCCLUSION query for the same bracketed range returns 0, the OCCLUSION predicate returns **FALSE**. Otherwise, the OCCLUSION predicate returns **TRUE**, which indicates that at least one multisample is visible. If the predicate was indicated to be a hint versus guaranteed, no result is ever propagated back to the application. This query type is a predicate and can be used to predicate rendering commands.

### `D3D10DDI_QUERY_STREAMOUTPUTSTATS`

The data that the driver associates with this query type is a [**D3D10_DDI_QUERY_DATA_SO_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_so_statistics) structure. This structure contains statistics for monitoring the amount of data that is streamed out at the stream-output stage of the pipeline. These statistics count only complete primitives (for example, points, lines, and triangles) that are streamed out. If the primitive type changes (for example, lines to triangles), the counting is not adjusted in any way. That is, the count is always total primitives, regardless of type.

> [!NOTE]
> The Direct3D runtime can call the driver's [**QueryGetData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querygetdata) function at any time to request these statistics. Therefore, it must be continually calculated accurately.

Only the difference between two independent statistic requests will provide meaningful information. The driver should calculate the difference between the statistic data that it receives when a call to its [**QueryBegin**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querybegin) function occurs and the statistic data that it receives when a call to its [**QueryEnd**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_queryend) function occurs.

### `D3D10DDI_QUERY_STREAMOVERFLOWPREDICATE`

The data that the driver associates with this query type is a BOOL. This BOOL is **TRUE** if any stream output overflowed. If two D3D10DDI_QUERY_STREAMOUTPUTSTATS queries were used to simultaneously monitor the same bracketed range as a STREAMOVERFLOWPREDICATE predicate type, the difference in the values in the **PrimitivesStorageNeeded** members of [**D3D10_DDI_QUERY_DATA_SO_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_so_statistics) would have resulted in a larger difference than the difference in the values in the **NumPrimitivesWritten** members. The STREAMOVERFLOWPREDICATE does not support the ability to be used as a hint. Therefore, the predicate type must be guaranteed. This query is a predicate and can be used to predicate rendering commands, which prevents an unwanted frame from being shown to the application.

In case of streaming to multiple buffers simultaneously, as soon as any one of them overflows, the stream output writes stop for all buffers, and the data for STREAMOVERFLOWPREDICATE becomes **TRUE**.

### `D3D11DDI_QUERY_PIPELINESTATS`

Supported in Windows 7 and later versions.

The data that the driver associates with this query type is a D3D11_DDI_QUERY_DATA_PIPELINE_STATISTICS structure. This structure contains statistics for each stage of the graphics pipeline. This query type is the same as the D3D11DDI_QUERY_PIPELINESTATS query type except D3D11_DDI_QUERY_DATA_PIPELINE_STATISTICS adds **HSInvocations** and **DSInvocations** members for hull and domain shaders.

### `D3D11DDI_QUERY_STREAMOUTPUTSTATS_STREAM0`

Supported in Windows 7 and later versions.

The data that the driver associates with this query type is a [**D3D10_DDI_QUERY_DATA_SO_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_so_statistics) structure.

### `D3D11DDI_QUERY_STREAMOUTPUTSTATS_STREAM1`

Supported in Windows 7 and later versions.

The data that the driver associates with this query type is a [**D3D10_DDI_QUERY_DATA_SO_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_so_statistics) structure.

### `D3D11DDI_QUERY_STREAMOUTPUTSTATS_STREAM2`

Supported in Windows 7 and later versions.

The data that the driver associates with this query type is a [**D3D10_DDI_QUERY_DATA_SO_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_so_statistics) structure.

### `D3D11DDI_QUERY_STREAMOUTPUTSTATS_STREAM3`

Supported in Windows 7 and later versions.

The data that the driver associates with this query type is a [**D3D10_DDI_QUERY_DATA_SO_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_so_statistics) structure.

### `D3D11DDI_QUERY_STREAMOVERFLOWPREDICATE_STREAM0`

Supported in Windows 7 and later versions.

The data that the driver associates with this query type is a BOOL. This BOOL is **TRUE** if the stream 0 output overflowed. If two D3D10DDI_QUERY_STREAMOUTPUTSTATS_STREAM0 queries were used to simultaneously monitor the same bracketed range as a STREAMOVERFLOWPREDICATE_STREAM0 predicate type, the difference in the values in the **PrimitivesStorageNeeded** members of [**D3D10_DDI_QUERY_DATA_SO_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_so_statistics) would have resulted in a larger difference than the difference in the values in the **NumPrimitivesWritten** members.

### `D3D11DDI_QUERY_STREAMOVERFLOWPREDICATE_STREAM1`

Supported in Windows 7 and later versions.

The data that the driver associates with this query type is a BOOL. This BOOL is **TRUE** if the stream 1 output overflowed. If two D3D10DDI_QUERY_STREAMOUTPUTSTATS_STREAM1 queries were used to simultaneously monitor the same bracketed range as a STREAMOVERFLOWPREDICATE_STREAM1 predicate type, the difference in the values in the **PrimitivesStorageNeeded** members of [**D3D10_DDI_QUERY_DATA_SO_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_so_statistics) would have resulted in a larger difference than the difference in the values in the **NumPrimitivesWritten** members.

### `D3D11DDI_QUERY_STREAMOVERFLOWPREDICATE_STREAM2`

Supported in Windows 7 and later versions.

The data that the driver associates with this query type is a BOOL. This BOOL is **TRUE** if the stream 2 output overflowed. If two D3D10DDI_QUERY_STREAMOUTPUTSTATS_STREAM1 queries were used to simultaneously monitor the same bracketed range as a STREAMOVERFLOWPREDICATE_STREAM2 predicate type, the difference in the values in the **PrimitivesStorageNeeded** members of [**D3D10_DDI_QUERY_DATA_SO_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_so_statistics) would have resulted in a larger difference than the difference in the values in the **NumPrimitivesWritten** members.

### `D3D11DDI_QUERY_STREAMOVERFLOWPREDICATE_STREAM3`

Supported in Windows 7 and later versions.

The data that the driver associates with this query type is a BOOL. This BOOL is **TRUE** if the stream 3 output overflowed. If two D3D10DDI_QUERY_STREAMOUTPUTSTATS_STREAM1 queries were used to simultaneously monitor the same bracketed range as a STREAMOVERFLOWPREDICATE_STREAM3 predicate type, the difference in the values in the **PrimitivesStorageNeeded** members of [**D3D10_DDI_QUERY_DATA_SO_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_so_statistics) would have resulted in a larger difference than the difference in the values in the **NumPrimitivesWritten** members.

### `D3D10DDI_COUNTER_GPU_IDLE`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of GPU idle time.

### `D3D10DDI_COUNTER_VERTEX_PROCESSING`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of time that the vertex shader is busy processing data.

### `D3D10DDI_COUNTER_GEOMETRY_PROCESSING`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of time that the geometry shader is busy processing data.

### `D3D10DDI_COUNTER_PIXEL_PROCESSING`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of time that the pixel shader is busy processing data.

### `D3D10DDI_COUNTER_OTHER_GPU_PROCESSING`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of time that GPU operations, other than vertex, geometry, and pixel shader operations, are busy processing data.

### `D3D10DDI_COUNTER_HOST_ADAPTER_BANDWIDTH_UTILIZATION`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of a theoretical maximum of adapter bandwidth utilization.

### `D3D10DDI_COUNTER_LOCAL_VIDMEM_BANDWIDTH_UTILIZATION`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of a theoretical maximum of video memory bandwidth utilization.

### `D3D10DDI_COUNTER_VERTEX_THROUGHPUT_UTILIZATION`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of a theoretical maximum of vertex throughput utilization.

### `D3D10DDI_COUNTER_TRISETUP_THROUGHPUT_UTILIZATION`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of a theoretical maximum of triangle-setup throughput utilization.

### `D3D10DDI_COUNTER_FILLRATE_THROUGHPUT_UTILIZATION`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of a theoretical maximum of fill-rate throughput utilization.

### `D3D10DDI_COUNTER_VERTEXSHADER_MEMORY_LIMITED`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of time that the vertex shader waits for memory to perform reads or writes of data (versus the percentage of time that the vertex shader computes math).

### `D3D10DDI_COUNTER_VERTEXSHADER_COMPUTATION_LIMITED`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of time that the vertex shader computes math (versus the percentage of time that the vertex shader waits for memory to perform reads or writes of data).

### `D3D10DDI_COUNTER_GEOMETRYSHADER_MEMORY_LIMITED`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of time that the geometry shader waits for memory to perform reads or writes of data (versus the percentage of time that the geometry shader computes math).

### `D3D10DDI_COUNTER_GEOMETRYSHADER_COMPUTATION_LIMITED`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of time that the geometry shader computes math (versus the percentage of time that the geometry shader waits for memory to perform reads or writes of data).

### `D3D10DDI_COUNTER_PIXELSHADER_MEMORY_LIMITED`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of time that the pixel shader waits for memory to perform reads or writes of data (versus the percentage of time that the pixel shader computes math).

### `D3D10DDI_COUNTER_PIXELSHADER_COMPUTATION_LIMITED`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of time that the pixel shader computes math (versus the percentage of time that the pixel shader waits for memory to perform reads or writes of data).

### `D3D10DDI_COUNTER_POST_TRANSFORM_CACHE_HIT_RATE`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of vertices that the geometry shader or pixel shader retrieved from a cache of vertices that were already transformed by the vertex shader.

A cache of transformed vertices (that is, vertices that the vertex shader ran against) exists immediately after the vertex shader. These vertices can be used by either the geometry shader or pixel shader. A 100% hit rate (result of a D3D10DDI_COUNTER_POST_TRANSFORM_CACHE_HIT_RATE query) indicates that every vertex necessary for the geometry shader or pixel shader was already transformed. Whereas a 0% hit rate indicates that every vertex required processing by the vertex shader before it could be used.

The driver can restructure algorithms and data to increase cache hit rates.

### `D3D10DDI_COUNTER_TEXTURE_CACHE_HIT_RATE`

The data that the driver associates with this query-counter type is a FLOAT32. The driver returns the percentage of texels or texture memory that a shader retrieved from a cache of texels that were already retrieved from video memory.

A cache of texture memory can exist between shader resource view or possibly constant buffer and shaders. A 100% hit rate indicates that every texel necessary for a shader was already available in the cache. Whereas a 0% hit rate indicates that every texel required retrieving data from video memory.

The driver can restructure algorithms and data to increase cache hit rates.

### `D3D10DDI_COUNTER_DEVICE_DEPENDENT_0`

The first available device-dependent query counter. Hardware vendors can use this value and any 32-bit value above 0x40000000 for a query counter for their devices.

## Remarks

Values for D3D10DDI_COUNTER_VERTEX_PROCESSING, D3D10DDI_COUNTER_GEOMETRY_PROCESSING, D3D10DDI_COUNTER_PIXEL_PROCESSING, and D3D10DDI_COUNTER_OTHER_GPU_PROCESSING can add up to a driver defined value, which is the number of detectable parallel units. This number is published by the driver as part of the graphics adapter capabilities. The number of detectable parallel units can be 1, 2, 3, or 4 depending on hardware architecture details, the ability of performance counters to discern where time is actually being spent, or at the complete discretion of the hardware vendor. For architectures that report the number of detectable parallel units equal to 1 (== 1) in the **NumDetectableParallelUnits** member of the [**D3D10DDI_COUNTER_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_counter_info) structure in response to a call to the [**CheckCounterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkcounterinfo) function, the following equation applies:

(D3D10DDI_COUNTER_VERTEX_PROCESSING + D3D10DDI_COUNTER_GEOMETRY_PROCESSING + D3D10DDI_COUNTER_PIXEL_PROCESSING + D3D10DDI_COUNTER_OTHER_GPU_PROCESSING) / **NumDetectableParallelUnits** = 1.0 - D3D10DDI_COUNTER_GPU_IDLE

The monitoring of all these counter identifiers (along with D3D10DDI_COUNTER_GPU_IDLE) still must comply with the rules of simultaneously active counters.

For architectures that report the number of detectable parallel units not equal to 1 (!= 1), the interaction between each busy metric is more complex. For example, with the number of detectable parallel units equal to 4 (== 4), D3D10DDI_COUNTER_VERTEX_PROCESSING and D3D10DDI_COUNTER_PIXEL_PROCESSING are equal to .25 (== .25), while the rest of the busy metrics are equal to 0 (== 0). D3D10DDI_COUNTER_GPU_IDLE could result in between .5 and .75 depending on how much actual overlap these parallel units achieved.

D3D10DDI_COUNTER_HOST_ADAPTER_BANDWIDTH_UTILIZATION, D3D10DDI_COUNTER_LOCAL_VIDMEM_BANDWIDTH_UTILIZATION, D3D10DDI_COUNTER_VERTEX_THROUGHPUT_UTILIZATION, D3D10DDI_COUNTER_TRISETUP_THROUGHPUT_UTILIZATION, and D3D10DDI_COUNTER_FILLRATE_THROUGHPUT_UTILIZATION all report a percentage of a bottleneck that can be used. Applications can then determine when a certain theoretical maximum is being stressed so that they can determine how to work around the bottleneck.

### Details for D3D10DDI_QUERY_PIPELINESTATS value

The data that the driver associates with this query type is a [**D3D10_DDI_QUERY_DATA_PIPELINE_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_pipeline_statistics) structure, which contains statistics for each stage of the graphics pipeline. For each stage, the value for number of invocations must fall between infinite cache and no cache. The clipper will appear to behave as the geometry shader (GS). The clipper will execute for each triangle. For each invocation, zero primitives will be generated if the original triangle is fully clipped, one primitive will be generated if the original triangle is not clipped at all (or the clipping results in only one triangle), two primitives will be generated if the original triangle was clipped and resulted in two triangles, and so on. In typical configurations of the pipeline, the value in the **GSPrimitives** member of **D3D10_DDI_QUERY_DATA_PIPELINE_STATISTICS** would be equal to the value in the **CInvocations** member. If rasterization is disabled and the pipeline is configured to only send primitives to stream output, the value in **GSPrimitives** would deviate from the value in **CInvocations** because **CInvocations** would not increment. The clipping statistics will be flexible with regards to guard band implementations. Therefore, when rendering triangles that extend beyond the viewport, the tests will ensure clipping falls between a range of values (numbers that assume an infinite guard band and numbers that assume a tight clipping rectangle around the viewport). All the values contain the number of events since the creation of the device context. Note that these statistics can be requested at any time, so they must be continually calculated accurately.

Only the difference between two independent statistic requests will provide meaningful information. The driver should calculate the difference between the statistic data that it receives when a call to its [**QueryBegin**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_querybegin) function occurs and the statistic data that it receives when a call to its [**QueryEnd**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_queryend) function occurs.

The following are examples of the interaction between the values in the **IAVertices**, **IAPrimitives**, and **VSInvocations** members of [**D3D10_DDI_QUERY_DATA_PIPELINE_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_pipeline_statistics) with respect to post vertex shader (VS) caching.

| Scenario | IAVertices valid value | IAPrimitives valid value | VSInvocations valid value |
|:--|:--|:--|:--|
| Draw indexed triangle strip of 4 primitives (with all indices the same value) | 6 | 4 | 1--12 |
| Draw indexed triangle list of 4 primitives (with all indices the same value) | 12 | 4 | 1--12 |
| Draw triangle strip of 4 primitives | 6 | 4 | 6--12 |
| Draw triangle list of 4 primitives | 12 | 4 | 6--12 |

Partial primitives will be allowed to fall within range of values, similar to the way vertex caching behaves. Therefore, when partial primitives are possible, statistics should fall between a pipeline that clips them as soon as possible (before even the input assembler (IA) counts them), or as late as possible (post clipper and pre-pixel shader (PS)). Stream output and a **NULL** GS are flexible as to whether they actually cause GS invocations to occur.

With respect to the value in the **PSInvocations** member of [**D3D10_DDI_QUERY_DATA_PIPELINE_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_pipeline_statistics), early depth and stencil optimizations might or might not prevent the work from the pixel shader from being realized. Therefore, when pixels fail a depth test, the value in **PSInvocations** might or might not be incremented depending on where the depth test actually occurs in the pipeline. If the pixel shader outputs depth, the value in **PSInvocations** must increment as expected, even if the output depth fails. The following example shows how the value in **PSInvocations** will be tested.

Consider the DSP (number of pixels that pass the depth and stencil tests) and DSF (number of pixels that fail either the depth or stencil test) quantities . DSP is roughly equivalent to the OCCLUSION query, except that OCCLUSION measures multi-samples (not pixels). In all cases, DSP <= the value in **PSInvocations** <= ( DSP + DSF ). When the pixel shader outputs depth, the value in **PSInvocations** is the sum of DSP and DSF. In addition, when a **NULL** pixel shader is bound to the pipeline, the value in **PSInvocations** does not increment.

With respect to the values in **IAVertices** and **VSInvocations**, adjacent vertex processing might be optimized out if the GS does not declare the adjacency vertices as inputs to the GS. Therefore, when the GS does not declare adjacent vertices as inputs, the values in **IAVertices** and **VSInvocations** might or might not reflect the work implied by the adjacent vertices. If the GS declares adjacent vertices, the value in **IAVertices** should include the adjacent vertices (with no regard to any post-VS caching), and the value in **VSInvocations** should include the adjacent vertices (along with any effects of post-VS caching).

## See also

[**CheckCounterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkcounterinfo)

[**D3D10DDIARG_CREATEQUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createquery)

[**D3D10DDI_COUNTER_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_counter_info)

[**D3D10_DDI_QUERY_DATA_PIPELINE_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_pipeline_statistics)

[**D3D10_DDI_QUERY_DATA_SO_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_so_statistics)

[**D3D10_DDI_QUERY_DATA_TIMESTAMP_DISJOINT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_timestamp_disjoint)