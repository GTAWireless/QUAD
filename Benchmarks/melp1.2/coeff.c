/*

2.4 kbps MELP Proposed Federal Standard speech coder

version 1.2

Copyright (c) 1996, Texas Instruments, Inc.  

Texas Instruments has intellectual property rights on the MELP
algorithm.  The Texas Instruments contact for licensing issues for
commercial and non-government use is William Gordon, Director,
Government Contracts, Texas Instruments Incorporated, Semiconductor
Group (phone 972 480 7442).


*/

/*  Coeff.c: filter coefficient file */
/*                                   */
/*                                                                  */
/* (C) 1993,1994  Texas Instruments                                 */
/*                                                                  */
#include	<stdio.h>
#include "melp.h"

/* Butterworth lowpass filter	*/
/* numerator */
float lpf_num[LPF_ORD+1] = {
      0.00105165,
      0.00630988,
      0.01577470,
      0.02103294,
      0.01577470,
      0.00630988,
      0.00105165};
/* denominator */
float lpf_den[LPF_ORD+1] = { 
      1.00000000,
     -2.97852993,
      4.13608100,
     -3.25976428,
      1.51727884,
     -0.39111723,
      0.04335699};

/* Butterworth bandpass filters */
float bpf_num[NUM_BANDS*(BPF_ORD+1)] = {
      0.00002883,
      0.00017296,
      0.00043239,
      0.00057652,
      0.00043239,
      0.00017296,
      0.00002883,
      0.00530041,
      0.00000000,
     -0.01590123,
      0.00000000,
      0.01590123,
      0.00000000,
     -0.00530041,
      0.03168934,
      0.00000000,
     -0.09506803,
     -0.00000000,
      0.09506803,
     -0.00000000,
     -0.03168934,
      0.03168934,
      0.00000000,
     -0.09506803,
      0.00000000,
      0.09506803,
      0.00000000,
     -0.03168934,
      0.00105165,
     -0.00630988,
      0.01577470,
     -0.02103294,
      0.01577470,
     -0.00630988,
      0.00105165};

float bpf_den[NUM_BANDS*(BPF_ORD+1)] = {
      1.00000000,
     -4.48456301,
      8.52900508,
     -8.77910797,
      5.14764268,
     -1.62771478,
      0.21658286,
      1.00000000,
     -4.42459751,
      8.79771496,
     -9.95335557,
      6.75320305,
     -2.60749972,
      0.45354593,
      1.00000000,
     -1.84699031,
      2.63060194,
     -2.21638838,
      1.57491237,
     -0.62291281,
      0.19782519,
      1.00000000,
      1.84699031,
      2.63060194,
      2.21638838,
      1.57491237,
      0.62291281,
      0.19782519,
      1.00000000,
      2.97852993,
      4.13608100,
      3.25976428,
      1.51727884,
      0.39111723,
      0.04335699};

/* Hamming window coefficents */
float win_cof[LPC_FRAME] = {
      0.08000000,
      0.08022927,
      0.08091685,
      0.08206205,
      0.08366374,
      0.08572031,
      0.08822971,
      0.09118945,
      0.09459658,
      0.09844769,
      0.10273895,
      0.10746609,
      0.11262438,
      0.11820869,
      0.12421345,
      0.13063268,
      0.13745997,
      0.14468852,
      0.15231113,
      0.16032019,
      0.16870773,
      0.17746538,
      0.18658441,
      0.19605574,
      0.20586991,
      0.21601716,
      0.22648736,
      0.23727007,
      0.24835455,
      0.25972975,
      0.27138433,
      0.28330667,
      0.29548489,
      0.30790684,
      0.32056016,
      0.33343221,
      0.34651017,
      0.35978102,
      0.37323150,
      0.38684823,
      0.40061762,
      0.41452595,
      0.42855935,
      0.44270384,
      0.45694532,
      0.47126959,
      0.48566237,
      0.50010932,
      0.51459603,
      0.52910806,
      0.54363095,
      0.55815022,
      0.57265140,
      0.58712003,
      0.60154169,
      0.61590200,
      0.63018666,
      0.64438141,
      0.65847211,
      0.67244472,
      0.68628531,
      0.69998007,
      0.71351536,
      0.72687769,
      0.74005374,
      0.75303036,
      0.76579464,
      0.77833383,
      0.79063545,
      0.80268724,
      0.81447716,
      0.82599349,
      0.83722473,
      0.84815969,
      0.85878747,
      0.86909747,
      0.87907943,
      0.88872338,
      0.89801971,
      0.90695917,
      0.91553283,
      0.92373215,
      0.93154896,
      0.93897547,
      0.94600427,
      0.95262835,
      0.95884112,
      0.96463638,
      0.97000835,
      0.97495168,
      0.97946144,
      0.98353313,
      0.98716270,
      0.99034653,
      0.99308145,
      0.99536472,
      0.99719408,
      0.99856769,
      0.99948420,
      0.99994268,
      0.99994268,
      0.99948420,
      0.99856769,
      0.99719408,
      0.99536472,
      0.99308145,
      0.99034653,
      0.98716270,
      0.98353313,
      0.97946144,
      0.97495168,
      0.97000835,
      0.96463638,
      0.95884112,
      0.95262835,
      0.94600427,
      0.93897547,
      0.93154896,
      0.92373215,
      0.91553283,
      0.90695917,
      0.89801971,
      0.88872338,
      0.87907943,
      0.86909747,
      0.85878747,
      0.84815969,
      0.83722473,
      0.82599349,
      0.81447716,
      0.80268724,
      0.79063545,
      0.77833383,
      0.76579464,
      0.75303036,
      0.74005374,
      0.72687769,
      0.71351536,
      0.69998007,
      0.68628531,
      0.67244472,
      0.65847211,
      0.64438141,
      0.63018666,
      0.61590200,
      0.60154169,
      0.58712003,
      0.57265140,
      0.55815022,
      0.54363095,
      0.52910806,
      0.51459603,
      0.50010932,
      0.48566237,
      0.47126959,
      0.45694532,
      0.44270384,
      0.42855935,
      0.41452595,
      0.40061762,
      0.38684823,
      0.37323150,
      0.35978102,
      0.34651017,
      0.33343221,
      0.32056016,
      0.30790684,
      0.29548489,
      0.28330667,
      0.27138433,
      0.25972975,
      0.24835455,
      0.23727007,
      0.22648736,
      0.21601716,
      0.20586991,
      0.19605574,
      0.18658441,
      0.17746538,
      0.16870773,
      0.16032019,
      0.15231113,
      0.14468852,
      0.13745997,
      0.13063268,
      0.12421345,
      0.11820869,
      0.11262438,
      0.10746609,
      0.10273895,
      0.09844769,
      0.09459658,
      0.09118945,
      0.08822971,
      0.08572031,
      0.08366374,
      0.08206205,
      0.08091685,
      0.08022927,
      0.08000000};

/* Bandpass filter coeffients */
float bp_cof[NUM_BANDS][MIX_ORD+1] = {
{
     -0.00000000,
     -0.00302890,
     -0.00701117,
     -0.01130619,
     -0.01494082,
     -0.01672586,
     -0.01544189,
     -0.01006619,
      0.00000000,
      0.01474923,
      0.03347158,
      0.05477206,
      0.07670890,
      0.09703726,
      0.11352143,
      0.12426379,
      0.12799355,
      0.12426379,
      0.11352143,
      0.09703726,
      0.07670890,
      0.05477206,
      0.03347158,
      0.01474923,
      0.00000000,
     -0.01006619,
     -0.01544189,
     -0.01672586,
     -0.01494082,
     -0.01130619,
     -0.00701117,
     -0.00302890,
     -0.00000000
},
{
     -0.00000000,
     -0.00249420,
     -0.00282091,
      0.00257679,
      0.01451271,
      0.02868120,
      0.03621179,
      0.02784469,
     -0.00000000,
     -0.04079870,
     -0.07849207,
     -0.09392213,
     -0.07451087,
     -0.02211575,
      0.04567473,
      0.10232715,
      0.12432599,
      0.10232715,
      0.04567473,
     -0.02211575,
     -0.07451087,
     -0.09392213,
     -0.07849207,
     -0.04079870,
     -0.00000000,
      0.02784469,
      0.03621179,
      0.02868120,
      0.01451271,
      0.00257679,
     -0.00282091,
     -0.00249420,
     -0.00000000
},
{
     -0.00000000,
     -0.00231491,
      0.00990113,
      0.02086129,
     -0.00000000,
     -0.03086123,
     -0.02180695,
      0.00769333,
     -0.00000000,
     -0.01127245,
      0.04726837,
      0.10106105,
     -0.00000000,
     -0.17904543,
     -0.16031428,
      0.09497157,
      0.25562154,
      0.09497157,
     -0.16031428,
     -0.17904543,
     -0.00000000,
      0.10106105,
      0.04726837,
     -0.01127245,
     -0.00000000,
      0.00769333,
     -0.02180695,
     -0.03086123,
     -0.00000000,
      0.02086129,
      0.00990113,
     -0.00231491,
     -0.00000000
},
{
     -0.00000000,
      0.00231491,
      0.00990113,
     -0.02086129,
      0.00000000,
      0.03086123,
     -0.02180695,
     -0.00769333,
     -0.00000000,
      0.01127245,
      0.04726837,
     -0.10106105,
      0.00000000,
      0.17904543,
     -0.16031428,
     -0.09497157,
      0.25562154,
     -0.09497157,
     -0.16031428,
      0.17904543,
      0.00000000,
     -0.10106105,
      0.04726837,
      0.01127245,
     -0.00000000,
     -0.00769333,
     -0.02180695,
      0.03086123,
      0.00000000,
     -0.02086129,
      0.00990113,
      0.00231491,
     -0.00000000
},
{
      0.00000000,
      0.00554149,
     -0.00981750,
      0.00856805,
     -0.00000000,
     -0.01267517,
      0.02162277,
     -0.01841647,
      0.00000000,
      0.02698425,
     -0.04686914,
      0.04150730,
     -0.00000000,
     -0.07353666,
      0.15896026,
     -0.22734513,
      0.25346255,
     -0.22734513,
      0.15896026,
     -0.07353666,
     -0.00000000,
      0.04150730,
     -0.04686914,
      0.02698425,
      0.00000000,
     -0.01841647,
      0.02162277,
     -0.01267517,
     -0.00000000,
      0.00856805,
     -0.00981750,
      0.00554149,
      0.00000000}};
/* Triangle pulse dispersion filter */
float disp_cof[DISP_ORD+1] = {
     -0.17304259,
     -0.01405709,
      0.01224406,
      0.11364226,
      0.00198199,
      0.00000658,
      0.04529633,
     -0.00092027,
     -0.00103078,
      0.02552787,
     -0.06339257,
     -0.00122031,
      0.01412525,
      0.24325127,
     -0.01767043,
     -0.00018612,
      0.05869485,
     -0.00327456,
      0.00607395,
      0.02753924,
     -0.03351673,
      0.00602189,
      0.01436539,
      0.82854582,
      0.00033165,
     -0.00360180,
      0.07343483,
     -0.00518645,
      0.01298488,
      0.02928440,
     -0.01989405,
      0.01216758,
      0.01180979,
     -0.38924775,
      0.00720325,
     -0.01154561,
      0.08426287,
     -0.00355720,
      0.02151233,
      0.02968464,
     -0.01247640,
      0.01854666,
      0.00076184,
     -0.07749640,
      0.01244697,
     -0.02721777,
      0.07266098,
      0.00472008,
      0.03526439,
      0.02674603,
     -0.00744038,
      0.02582623,
      0.00019707,
     -0.02825247,
      0.01720989,
     -0.06004292,
     -0.07076744,
      0.00914347,
      0.06082730,
      0.01805528,
     -0.00318634,
      0.03444110,
      0.00026302,
     -0.01053809,
      0.02165922};





