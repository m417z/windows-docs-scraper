# CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT structure

A templated helper structure used to encapsulate subobject type and subobject data pairs as a single object suitable for a stream description.

## Members

**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT**

Creates a new, uninitialized, instance of a CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT.

**CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT(**InnerStructType** const &i)**

Creates a new CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT template instance, initialized with a subobject type of [**D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_pipeline_state_subobject_type) and subobject data copied from *i*. Both the subobject type and subobject data type are given as template parameters, **Type** and **InnerStructType**, respectively. For more information, see Remarks below.

**operator=(**InnerStructType** const& i)**

Copy-assignment operator.

**operator **InnerStructType**() const**

Implicit conversion to the subobject data type given by the **InnerStructType** template parameter.

## Remarks

CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT is a template defined as follows:

```C++
template <typename InnerStructType, D3D12_PIPELINE_STATE_SUBOBJECT_TYPE Type, typename DefaultArg = InnerStructType>
class alignas(void*) CD3DX12_PIPELINE_STATE_STREAM_SUBOBJECT
{
private:
    D3D12_PIPELINE_STATE_SUBOBJECT_TYPE _Type;
    InnerStructType _Inner;
public:
    CD3DX12_PIPELINE_STATE_STREAM_SUBOBJECT() : _Type(Type), _Inner(DefaultArg()) {}
    CD3DX12_PIPELINE_STATE_STREAM_SUBOBJECT(InnerStructType const& i) : _Type(Type), _Inner(i) {}
    CD3DX12_PIPELINE_STATE_STREAM_SUBOBJECT& operator=(InnerStructType const& i) { _Inner = i; return *this; }
    operator InnerStructType() const { return _Inner; }
};

```

The template parameter **InnerStructType** specifies the subobject data type; that is, the subobject details to be encoded into a stream. The template parameter **Type** specifies the subobject type; that is, the type of the structure specified by the template parameter **InnerStructType**. The template parameter **DefaultArg** specifies an optional value that the subobject data will be initialized to when an instance of the corresponding template instantiation is default-constructed; for example, to default-construct a [**CD3DX12\_PIPELINE\_STATE\_STREAM\_BLEND\_DESC**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-blend-desc) initialized with common blend-state defaults using [**CD3DX12\_DEFAULT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-default).

Here are the template instantiations that are defined:

- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_FLAGS**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-flags)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_NODE\_MASK**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-node-mask)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_ROOT\_SIGNATURE**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-root-signature)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_INPUT\_LAYOUT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-input-layout)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_IB\_STRIP\_CUT\_VALUE**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-ib-strip-cut-value)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_PRIMITIVE\_TOPOLOGY**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-primitive-topology)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_VS**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-vs)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_GS**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-gs)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_STREAM\_OUTPUT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-stream-output)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_HS**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-hs)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_DS**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-ds)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_PS**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-ps)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_CS**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-cs)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_BLEND\_DESC**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-blend-desc)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_DEPTH\_STENCIL**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-depth-stencil)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_DEPTH\_STENCIL1**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-depth-stencil1)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_DEPTH\_STENCIL\_FORMAT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-depth-stencil-format)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_RASTERIZER**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-rasterizer)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_RENDER\_TARGET\_FORMATS**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-render-target-formats)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_SAMPLE\_DESC**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-sample-desc)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_SAMPLE\_MASK**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-sample-mask)
- [**CD3DX12\_PIPELINE\_STATE\_STREAM\_CACHED\_PSO**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-cached-pso)

The [**CD3DX12\_PIPELINE\_STATE\_STREAM\_BLEND\_DESC**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-blend-desc), [**CD3DX12\_PIPELINE\_STATE\_STREAM\_DEPTH\_STENCIL**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-depth-stencil), [**CD3DX12\_PIPELINE\_STATE\_STREAM\_DEPTH\_STENCIL1**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-depth-stencil1), and [**CD3DX12\_PIPELINE\_STATE\_STREAM\_RASTERIZER**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-rasterizer) structures are defined to initialize their subobject data with common defaults using [**CD3DX12\_DEFAULT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-default).

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

[**D3D12\_PIPELINE\_STATE\_SUBOBJECT\_TYPE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_pipeline_state_subobject_type)

