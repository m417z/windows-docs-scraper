struct BoundingFrustum {
  size_t                            CORNER_COUNT;
  XMFLOAT3                          Origin;
  XMFLOAT4                          Orientation;
  float                             RightSlope;
  float                             LeftSlope;
  float                             TopSlope;
  float                             BottomSlope;
  float                             Near;
  float                             Far;
  void                              BoundingFrustum() noexcept;
  void                              BoundingFrustum(
    const BoundingFrustum & unnamedParam1
  );
  BoundingFrustum &                 operator=(
    const BoundingFrustum & unnamedParam1
  );
  void                              BoundingFrustum(
    BoundingFrustum && unnamedParam1
  );
  BoundingFrustum &                 operator=(
    BoundingFrustum && unnamedParam1
  );
  void                              BoundingFrustum(
    const XMFLOAT3 & origin,
    const XMFLOAT4 & orientation,
    float            rightSlope,
    float            leftSlope,
    float            topSlope,
    float            bottomSlope,
    float            nearPlane,
    float            farPlane
  ) noexcept;
  void                              BoundingFrustum(
    CXMMATRIX Projection,
    bool      rhcoords
  ) noexcept;
  void XM_CALLCONV                  Transform(
    BoundingFrustum & Out,
    FXMMATRIX         M
  ) noexcept;
  void XM_CALLCONV                  Transform(
    BoundingFrustum & Out,
    float             Scale,
    FXMVECTOR         Rotation,
    FXMVECTOR         Translation
  ) noexcept;
  void                              GetCorners(
    XMFLOAT3 *Corners
  ) noexcept;
  ContainmentType XM_CALLCONV       Contains(
    FXMVECTOR Point
  ) noexcept;
  ContainmentType XM_CALLCONV       Contains(
    FXMVECTOR V0,
    FXMVECTOR V1,
    FXMVECTOR V2
  ) noexcept;
  ContainmentType                   Contains(
    const BoundingSphere & sp
  ) noexcept;
  ContainmentType                   Contains(
    const BoundingBox & box
  ) noexcept;
  ContainmentType                   Contains(
    const BoundingOrientedBox & box
  ) noexcept;
  ContainmentType                   Contains(
    const BoundingFrustum & fr
  ) noexcept;
  bool                              Intersects(
    const BoundingSphere & sh
  ) noexcept;
  bool                              Intersects(
    const BoundingBox & box
  ) noexcept;
  bool                              Intersects(
    const BoundingOrientedBox & box
  ) noexcept;
  bool                              Intersects(
    const BoundingFrustum & fr
  ) noexcept;
  bool XM_CALLCONV                  Intersects(
    FXMVECTOR V0,
    FXMVECTOR V1,
    FXMVECTOR V2
  ) noexcept;
  PlaneIntersectionType XM_CALLCONV Intersects(
    FXMVECTOR Plane
  ) noexcept;
  bool XM_CALLCONV                  Intersects(
    FXMVECTOR rayOrigin,
    FXMVECTOR Direction,
    float &   Dist
  ) noexcept;
  ContainmentType XM_CALLCONV       ContainedBy(
    FXMVECTOR Plane0,
    FXMVECTOR Plane1,
    FXMVECTOR Plane2,
    GXMVECTOR Plane3,
    HXMVECTOR Plane4,
    HXMVECTOR Plane5
  ) noexcept;
  void                              GetPlanes(
    XMVECTOR *NearPlane,
    XMVECTOR *FarPlane,
    XMVECTOR *RightPlane,
    XMVECTOR *LeftPlane,
    XMVECTOR *TopPlane,
    XMVECTOR *BottomPlane
  ) noexcept;
  void XM_CALLCONV                  CreateFromMatrix(
    BoundingFrustum & Out,
    FXMMATRIX         Projection,
    bool              rhcoords
  ) noexcept;
};