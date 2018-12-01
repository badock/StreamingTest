#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
// Buffer Definitions: 
//
// cbuffer Direct2DTransforms
// {
//
//   float2x1 sceneToOutputX;           // Offset:    0 Size:     8
//   float2x1 sceneToOutputY;           // Offset:    8 Size:     8
//   float2x1 sceneToInput0X;           // Offset:   16 Size:     8
//   float2x1 sceneToInput0Y;           // Offset:   24 Size:     8
//
// }
//
// cbuffer constants
// {
//
//   uint2 displayedFrameSize;          // Offset:    0 Size:     8
//   uint2 originalFrameSize;           // Offset:    8 Size:     8
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- -------------- ------
// Direct2DTransforms                cbuffer      NA          NA            cb0      1 
// constants                         cbuffer      NA          NA            cb1      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// MESH_POSITION            0   xy          0     NONE   float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float   xyzw
// SCENE_POSITION           0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 0   xyzw        2     NONE   float   xyzw
//
//
// Constant buffer to DX9 shader constant mappings:
//
// Target Reg Buffer  Start Reg # of Regs        Data Conversion
// ---------- ------- --------- --------- ----------------------
// c1         cb0             0         2  ( FLT, FLT, FLT, FLT)
// c3         cb1             0         1  (UINT,UINT,UINT,UINT)
//
//
// Runtime generated constant mappings:
//
// Target Reg                               Constant Description
// ---------- --------------------------------------------------
// c0                              Vertex Shader position offset
//
//
// Level9 shader bytecode:
//
    vs_2_x
    def c4, 0, 1, -1, 0
    dcl_texcoord v0
    mul r0, v0.xyxy, c3
    mad oT1.xy, r0.zwzw, c2.xzzw, c2.ywzw
    mad r0.zw, r0.xyxy, c1.xyxz, c1.xyyw
    mov oT0.xy, r0
    add oPos.xy, r0.zwzw, c0
    mov oPos.zw, c4.xyxy
    mov oT0.zw, c4.xyxy
    mad oT1.zw, v0.y, c4.xyzx, c4.y

// approximately 8 instruction slots used
vs_4_0
dcl_constantbuffer CB0[2], immediateIndexed
dcl_constantbuffer CB1[1], immediateIndexed
dcl_input v0.xy
dcl_output_siv o0.xyzw, position
dcl_output o1.xyzw
dcl_output o2.xyzw
dcl_temps 1
mov o0.zw, l(0,0,0,1.000000)
utof r0.xyzw, cb1[0].xyzw
mul r0.xyzw, r0.xyzw, v0.xyxy
mad o0.xy, r0.xyxx, cb0[0].xzxx, cb0[0].ywyy
mov o1.xy, r0.xyxx
mad o2.xy, r0.zwzz, cb0[1].xzxx, cb0[1].ywyy
mov o1.zw, l(0,0,0,1.000000)
add o2.z, -v0.y, l(1.000000)
mov o2.w, l(1.000000)
ret 
// Approximately 10 instruction slots used
#endif

const BYTE VERTEX_SHADER_main[] =
{
     68,  88,  66,  67, 250,  22, 
     37,  62, 187,  16, 171, 126, 
     60, 137, 116, 180,  61, 131, 
    100,  47,   1,   0,   0,   0, 
    212,   5,   0,   0,   6,   0, 
      0,   0,  56,   0,   0,   0, 
     44,   1,   0,   0, 176,   2, 
      0,   0,  44,   3,   0,   0, 
     32,   5,   0,   0,  88,   5, 
      0,   0,  65, 111, 110,  57, 
    236,   0,   0,   0, 236,   0, 
      0,   0,   0,   2, 254, 255, 
    172,   0,   0,   0,  64,   0, 
      0,   0,   2,   0,  36,   0, 
      0,   0,  60,   0,   0,   0, 
     60,   0,   0,   0,  36,   0, 
      1,   0,  60,   0,   0,   0, 
      0,   0,   2,   0,   1,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   3,   0, 
      3,   3,   3,   3,   0,   0, 
      0,   0,   1,   2, 254, 255, 
     81,   0,   0,   5,   4,   0, 
     15, 160,   0,   0,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128, 191,   0,   0,   0,   0, 
     31,   0,   0,   2,   5,   0, 
      0, 128,   0,   0,  15, 144, 
      5,   0,   0,   3,   0,   0, 
     15, 128,   0,   0,  68, 144, 
      3,   0, 228, 160,   4,   0, 
      0,   4,   1,   0,   3, 224, 
      0,   0, 238, 128,   2,   0, 
    232, 160,   2,   0, 237, 160, 
      4,   0,   0,   4,   0,   0, 
     12, 128,   0,   0,  68, 128, 
      1,   0, 132, 160,   1,   0, 
    212, 160,   1,   0,   0,   2, 
      0,   0,   3, 224,   0,   0, 
    228, 128,   2,   0,   0,   3, 
      0,   0,   3, 192,   0,   0, 
    238, 128,   0,   0, 228, 160, 
      1,   0,   0,   2,   0,   0, 
     12, 192,   4,   0,  68, 160, 
      1,   0,   0,   2,   0,   0, 
     12, 224,   4,   0,  68, 160, 
      4,   0,   0,   4,   1,   0, 
     12, 224,   0,   0,  85, 144, 
      4,   0,  36, 160,   4,   0, 
     85, 160, 255, 255,   0,   0, 
     83,  72,  68,  82, 124,   1, 
      0,   0,  64,   0,   1,   0, 
     95,   0,   0,   0,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,  89,   0,   0,   4, 
     70, 142,  32,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     95,   0,   0,   3,  50,  16, 
     16,   0,   0,   0,   0,   0, 
    103,   0,   0,   4, 242,  32, 
     16,   0,   0,   0,   0,   0, 
      1,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      1,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      2,   0,   0,   0, 104,   0, 
      0,   2,   1,   0,   0,   0, 
     54,   0,   0,   8, 194,  32, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    128,  63,  86,   0,   0,   6, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  70,  20, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,  11,  50,  32, 
     16,   0,   0,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0, 134, 128,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 214, 133,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  54,   0,   0,   5, 
     50,  32,  16,   0,   1,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  11,  50,  32,  16,   0, 
      2,   0,   0,   0, 230,  10, 
     16,   0,   0,   0,   0,   0, 
    134, 128,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
    214, 133,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     54,   0,   0,   8, 194,  32, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    128,  63,   0,   0,   0,   8, 
     66,  32,  16,   0,   2,   0, 
      0,   0,  26,  16,  16, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  54,   0, 
      0,   5, 130,  32,  16,   0, 
      2,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 116,   0,   0,   0, 
     10,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  82,  68,  69,  70, 
    236,   1,   0,   0,   2,   0, 
      0,   0, 124,   0,   0,   0, 
      2,   0,   0,   0,  28,   0, 
      0,   0,   0,   4, 254, 255, 
      0,   1,   0,   0, 194,   1, 
      0,   0,  92,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 111,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     68, 105, 114, 101,  99, 116, 
     50,  68,  84, 114,  97, 110, 
    115, 102, 111, 114, 109, 115, 
      0,  99, 111, 110, 115, 116, 
     97, 110, 116, 115,   0, 171, 
    171, 171,  92,   0,   0,   0, 
      4,   0,   0,   0, 172,   0, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 111,   0,   0,   0, 
      2,   0,   0,   0,  92,   1, 
      0,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  12,   1,   0,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,   2,   0,   0,   0, 
     28,   1,   0,   0,   0,   0, 
      0,   0,  44,   1,   0,   0, 
      8,   0,   0,   0,   8,   0, 
      0,   0,   2,   0,   0,   0, 
     28,   1,   0,   0,   0,   0, 
      0,   0,  59,   1,   0,   0, 
     16,   0,   0,   0,   8,   0, 
      0,   0,   2,   0,   0,   0, 
     28,   1,   0,   0,   0,   0, 
      0,   0,  74,   1,   0,   0, 
     24,   0,   0,   0,   8,   0, 
      0,   0,   2,   0,   0,   0, 
     28,   1,   0,   0,   0,   0, 
      0,   0, 115,  99, 101, 110, 
    101,  84, 111,  79, 117, 116, 
    112, 117, 116,  88,   0, 171, 
      3,   0,   3,   0,   2,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 115,  99, 
    101, 110, 101,  84, 111,  79, 
    117, 116, 112, 117, 116,  89, 
      0, 115,  99, 101, 110, 101, 
     84, 111,  73, 110, 112, 117, 
    116,  48,  88,   0, 115,  99, 
    101, 110, 101,  84, 111,  73, 
    110, 112, 117, 116,  48,  89, 
      0, 171, 171, 171, 140,   1, 
      0,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,   2,   0, 
      0,   0, 160,   1,   0,   0, 
      0,   0,   0,   0, 176,   1, 
      0,   0,   8,   0,   0,   0, 
      8,   0,   0,   0,   2,   0, 
      0,   0, 160,   1,   0,   0, 
      0,   0,   0,   0, 100, 105, 
    115, 112, 108,  97, 121, 101, 
    100,  70, 114,  97, 109, 101, 
     83, 105, 122, 101,   0, 171, 
      1,   0,  19,   0,   1,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 111, 114, 
    105, 103, 105, 110,  97, 108, 
     70, 114,  97, 109, 101,  83, 
    105, 122, 101,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  49,  48,  46, 
     49,   0, 171, 171,  73,  83, 
     71,  78,  48,   0,   0,   0, 
      1,   0,   0,   0,   8,   0, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   3,   3, 
      0,   0,  77,  69,  83,  72, 
     95,  80,  79,  83,  73,  84, 
     73,  79,  78,   0, 171, 171, 
     79,  83,  71,  78, 116,   0, 
      0,   0,   3,   0,   0,   0, 
      8,   0,   0,   0,  80,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,  92,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     15,   0,   0,   0, 107,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
     15,   0,   0,   0,  83,  86, 
     95,  80,  79,  83,  73,  84, 
     73,  79,  78,   0,  83,  67, 
     69,  78,  69,  95,  80,  79, 
     83,  73,  84,  73,  79,  78, 
      0,  84,  69,  88,  67,  79, 
     79,  82,  68,   0
};
