## Description

Represents a rate control structure definition for constant quantization parameter mode.

## Members

### `ConstantQP_FullIntracodedFrame`

A UINT64 specifying the quantization parameter that should be used for each fully intra-encoded frame.

### `ConstantQP_InterPredictedFrame_PrevRefOnly`

A UINT64 specifying the quantization parameter that should be used for each encoded frame that has inter-picture references to pictures (in display order) before the current one.

### `ConstantQP_InterPredictedFrame_BiDirectionalRef`

A UINT64 specifying the quantization parameter that should be used for each encoded frame that has inter-picture references to pictures (in display order) both from previous and next frames.

## Remarks

## See also