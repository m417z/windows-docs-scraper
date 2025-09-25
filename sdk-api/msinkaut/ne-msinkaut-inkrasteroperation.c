typedef enum InkRasterOperation {
  IRO_Black = 1,
  IRO_NotMergePen = 2,
  IRO_MaskNotPen = 3,
  IRO_NotCopyPen = 4,
  IRO_MaskPenNot = 5,
  IRO_Not = 6,
  IRO_XOrPen = 7,
  IRO_NotMaskPen = 8,
  IRO_MaskPen = 9,
  IRO_NotXOrPen = 10,
  IRO_NoOperation = 11,
  IRO_MergeNotPen = 12,
  IRO_CopyPen = 13,
  IRO_MergePenNot = 14,
  IRO_MergePen = 15,
  IRO_White = 16
} ;