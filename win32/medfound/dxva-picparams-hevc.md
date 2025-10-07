# DXVA\_PicParams\_HEVC structure

Provides the picture-level parameters of a compressed picture for HEVC video decoding.

## Members

**PicWidthInMinCbsY**

**PicHeightInMinCbsY**

**chroma\_format\_idc**

**separate\_colour\_plane\_flag**

**bit\_depth\_luma\_minus8**

**bit\_depth\_chroma\_minus8**

**log2\_max\_pic\_order\_cnt\_lsb\_minus4**

**NoPicReorderingFlag**

**NoBiPredFlag**

**ReservedBits1**

**wFormatAndSequenceInfoFlags**

**CurrPic**

**sps\_max\_dec\_pic\_buffering\_minus1**

**log2\_min\_luma\_coding\_block\_size\_minus3**

**log2\_diff\_max\_min\_luma\_coding\_block\_size**

**log2\_min\_transform\_block\_size\_minus2**

**log2\_diff\_max\_min\_transform\_block\_size**

**max\_transform\_hierarchy\_depth\_inter**

**max\_transform\_hierarchy\_depth\_intra**

**num\_short\_term\_ref\_pic\_sets**

**num\_long\_term\_ref\_pics\_sps**

**num\_ref\_idx\_l0\_default\_active\_minus1**

**num\_ref\_idx\_l1\_default\_active\_minus1**

**init\_qp\_minus26**

**ucNumDeltaPocsOfRefRpsIdx**

**wNumBitsForShortTermRPSInSlice**

**ReservedBits2**

**scaling\_list\_enabled\_flag**

**amp\_enabled\_flag**

**sample\_adaptive\_offset\_enabled\_flag**

**pcm\_enabled\_flag**

**pcm\_sample\_bit\_depth\_luma\_minus1**

**pcm\_sample\_bit\_depth\_chroma\_minus1**

**log2\_min\_pcm\_luma\_coding\_block\_size\_minus3**

**log2\_diff\_max\_min\_pcm\_luma\_coding\_block\_size**

**pcm\_loop\_filter\_disabled\_flag**

**long\_term\_ref\_pics\_present\_flag**

**sps\_temporal\_mvp\_enabled\_flag**

**strong\_intra\_smoothing\_enabled\_flag**

**dependent\_slice\_segments\_enabled\_flag**

**output\_flag\_present\_flag**

**num\_extra\_slice\_header\_bits**

**sign\_data\_hiding\_enabled\_flag**

**cabac\_init\_present\_flag**

**ReservedBits3**

**dwCodingParamToolFlags**

**constrained\_intra\_pred\_flag**

**transform\_skip\_enabled\_flag**

**cu\_qp\_delta\_enabled\_flag**

**pps\_slice\_chroma\_qp\_offsets\_present\_flag**

**weighted\_pred\_flag**

**weighted\_bipred\_flag**

**transquant\_bypass\_enabled\_flag**

**tiles\_enabled\_flag**

**entropy\_coding\_sync\_enabled\_flag**

**uniform\_spacing\_flag**

**loop\_filter\_across\_tiles\_enabled\_flag**

**pps\_loop\_filter\_across\_slices\_enabled\_flag**

**deblocking\_filter\_override\_enabled\_flag**

**pps\_deblocking\_filter\_disabled\_flag**

**lists\_modification\_present\_flag**

**slice\_segment\_header\_extension\_present\_flag**

**IrapPicFlag**

**IdrPicFlag**

**IntraPicFlag**

**ReservedBits4**

**dwCodingSettingPicturePropertyFlags**

**pps\_cb\_qp\_offset**

**pps\_cr\_qp\_offset**

**num\_tile\_columns\_minus1**

**num\_tile\_rows\_minus1**

**column\_width\_minus1**

**row\_height\_minus1**

**diff\_cu\_qp\_delta\_depth**

**pps\_beta\_offset\_div2**

**pps\_tc\_offset\_div2**

**log2\_parallel\_merge\_level\_minus2**

**CurrPicOrderCntVal**

**RefPicList**

**ReservedBits5**

**PicOrderCntValList**

**RefPicSetStCurrBefore**

**RefPicSetStCurrAfter**

**RefPicSetLtCurr**

**ReservedBits6**

**ReservedBits7**

**StatusReportFeedbackNumber**

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8.1 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 R2 \[desktop apps only\]<br> |
| Header<br> | Dxva.h |

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/win32/medfound/media-foundation-structures)

