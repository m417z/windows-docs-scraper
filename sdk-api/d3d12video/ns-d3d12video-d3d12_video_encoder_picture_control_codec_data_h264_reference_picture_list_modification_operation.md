## Description

Represents a picture list modification operation for H264 video encoding.

## Members

### `modification_of_pic_nums_idc`

Together with abs_diff_pic_num_minus1 or long_term_pic_num specifies which of the reference pictures are re-mapped.

### `abs_diff_pic_num_minus1`

Specifies the absolute difference between the picture number of the picture being moved to the current index in the list and the picture number prediction value.

### `long_term_pic_num`

Specifies the long-term picture number of the picture being moved to the current index in the list.

## Remarks

For more information, refer to H264 specification for more details: section 7.4.3.1 "Reference picture list modification semantics".
.

## See also