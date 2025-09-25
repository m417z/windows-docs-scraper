typedef enum ExtendedArrayDimensionFlags {
  ExtendedArrayLengthIsOffset32,
  ExtendedArrayLengthIsOffset64,
  ExtendedArrayLengthIsOffset,
  ExtendedArrayLowerBoundIsOffset32,
  ExtendedArrayLowerBoundIsOffset64,
  ExtendedArrayLowerBoundIsOffset,
  ExtendedArrayStrideIsOffset32,
  ExtendedArrayStrideIsOffset64,
  ExtendedArrayStrideIsOffset,
  ExtendedArrayStrideIsComputedByNextRank,
  ExtendedArrayStrideIsComputedByPreviousRank,
  ExtendedArrayStrideIsComputed
} ;