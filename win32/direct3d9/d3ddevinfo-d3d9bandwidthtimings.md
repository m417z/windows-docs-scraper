# D3DDEVINFO\_D3D9BANDWIDTHTIMINGS structure

Throughput metrics for help in understanding the performance of an application.

## Members

**MaxBandwidthUtilized**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The bandwidth or maximum data transfer rate from the host CPU to the GPU. This is typically the bandwidth of the PCI or AGP bus which connects the CPU and the GPU.

**FrontEndUploadMemoryUtilizedPercent**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Memory utilized percentage when uploading data from the host CPU to the GPU.

**VertexRateUtilizedPercent**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Vertex throughput percentage. This is the number of vertices processed compared to the theoretical maximum vertex processing rate.

**TriangleSetupRateUtilizedPercent**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Triangle set-up throughput percentage. This is the number of triangles that are set up for rasterization compared to the theoretical maximum triangle set-up rate.

**FillRateUtilizedPercent**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pixel fill throughput percentage. This is the number of pixels that are filled compared to the theoretical pixel fill.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**GetData**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dquery9-getdata)

