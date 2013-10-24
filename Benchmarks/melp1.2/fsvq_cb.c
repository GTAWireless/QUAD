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

/* VQ Codebook file           */
/* (C) 1995 Texas Instruments */

#include	<stdio.h>
#include	"melp.h"

int fsvq_weighted = 0;

float fsvq_cb[2560] = {
0.822998, 1.496297, 0.584847, 1.313507, 0.846008, 0.614041, 0.615298, 0.881819, 1.227331, 0.902116, 
1.248150, 1.020382, 0.517184, 1.489079, 0.650498, 0.716904, 0.650349, 1.260358, 0.871024, 0.907932, 
1.167392, 1.468091, 0.743322, 0.712255, 1.564293, 0.721041, 0.528277, 0.657527, 0.763228, 0.846655, 
1.043080, 1.570270, 0.444422, 0.933200, 1.211773, 0.669870, 0.932675, 0.806473, 0.913787, 0.868244, 
0.759126, 1.037894, 1.126967, 1.133186, 0.789090, 0.807399, 1.054906, 0.949898, 1.007863, 1.119437, 
0.977225, 1.130888, 1.044601, 1.432985, 0.819888, 0.517787, 0.932401, 0.964477, 0.886867, 0.895436, 
0.666187, 1.364039, 1.088940, 0.902131, 1.110838, 0.980791, 0.926721, 0.867719, 0.925053, 0.913544, 
0.983185, 1.460579, 0.732273, 0.923475, 1.088579, 0.952291, 0.789664, 1.025082, 0.904670, 0.854338, 
0.697275, 1.651033, 0.506420, 0.809603, 1.113992, 1.083678, 0.629739, 0.986236, 0.871250, 0.997090, 
0.749416, 1.354976, 0.731452, 1.281438, 1.080946, 1.037235, 0.748186, 0.821493, 0.879839, 0.965350, 
0.976897, 2.009469, 0.741592, 0.606862, 0.644927, 0.687413, 0.760360, 0.833318, 0.869851, 0.810534, 
0.576891, 1.527863, 0.657703, 1.006739, 1.226803, 0.786733, 0.991212, 0.821165, 1.014984, 0.878058, 
0.517211, 1.220859, 0.886556, 0.980153, 0.884365, 1.041315, 0.949276, 0.881296, 1.373464, 0.890748, 
0.651809, 1.106789, 0.885180, 1.329281, 1.124388, 0.626778, 1.261132, 0.822453, 0.966925, 0.806183, 
0.614335, 1.430380, 0.899696, 0.847168, 0.624567, 1.307056, 1.360741, 0.735438, 0.854307, 0.674763, 
0.830604, 1.373081, 0.785967, 0.735951, 0.968745, 1.100706, 0.927619, 0.728449, 1.292031, 0.884959, 
1.084085, 1.385767, 0.448480, 1.297458, 0.770611, 0.719263, 1.080766, 0.909836, 0.838299, 0.909742, 
1.244608, 1.158451, 0.615757, 1.169599, 1.032735, 0.921809, 0.916509, 1.060343, 0.836990, 0.767101, 
1.313869, 1.341417, 0.481710, 0.685601, 1.086817, 1.003461, 0.762127, 0.832518, 1.081618, 0.917168, 
1.427137, 0.932544, 0.595881, 0.652610, 1.073852, 0.847480, 1.264058, 0.899502, 0.899264, 0.958964, 
1.027745, 1.214124, 0.896291, 0.972030, 0.841943, 0.738307, 1.048254, 1.077882, 0.952564, 1.056319, 
0.952252, 1.098463, 0.690316, 1.175721, 0.911712, 0.962678, 0.859269, 1.138901, 1.074558, 0.924091, 
0.902314, 1.163750, 1.143587, 0.814860, 0.923235, 0.973077, 1.098871, 0.966014, 0.968856, 0.893133, 
1.133879, 1.110463, 0.687589, 0.793794, 1.026535, 1.076900, 1.185281, 0.821843, 0.845464, 1.079782, 
0.623910, 1.269921, 0.722072, 0.990256, 1.183314, 1.161476, 0.677381, 1.199311, 0.902081, 0.883634, 
0.585861, 1.189163, 0.882952, 1.134136, 0.900218, 1.263223, 0.995922, 1.011126, 0.906268, 0.863339, 
0.687616, 1.562003, 0.815795, 0.701934, 0.789752, 1.204232, 0.821560, 1.168157, 0.888904, 0.860778, 
0.950686, 1.329037, 0.692678, 0.754646, 1.095995, 1.446339, 0.941535, 0.710369, 0.789949, 0.826271, 
0.520026, 1.293024, 0.938993, 0.990412, 0.897114, 0.914170, 1.358696, 0.952011, 0.936183, 0.837973, 
0.669622, 1.291638, 0.749196, 1.167486, 1.042641, 0.721329, 1.005261, 1.252692, 0.883186, 0.854416, 
0.497926, 1.222508, 1.403952, 0.799058, 0.798533, 0.793545, 1.264461, 0.958949, 0.843825, 0.909886, 
0.891705, 1.342163, 0.761635, 0.758182, 0.987397, 1.008477, 1.377249, 0.845635, 0.845744, 0.822265, 
1.174305, 0.454482, 0.432532, 0.691549, 1.066271, 0.890505, 0.845957, 1.125649, 1.338280, 1.204068, 
1.607432, 0.688224, 0.500617, 1.288348, 0.678978, 0.674969, 1.047764, 1.012974, 0.954688, 0.803209, 
1.739179, 0.919542, 0.639494, 0.775935, 1.021945, 0.991820, 0.887633, 0.876449, 0.796800, 0.771028, 
1.620174, 1.211703, 0.610139, 1.372774, 1.057336, 0.618126, 0.642995, 0.667444, 0.666172, 0.676810, 
1.219952, 0.844191, 1.016601, 0.867402, 1.006595, 0.940309, 0.893858, 0.963053, 0.730414, 1.286290, 
1.251753, 1.004762, 0.777132, 1.203828, 0.656382, 0.657205, 1.233246, 0.874799, 1.106710, 0.855250, 
1.348819, 0.791939, 1.030755, 0.765314, 1.014939, 1.044297, 0.747682, 1.309667, 0.853913, 0.723126, 
1.262759, 1.109681, 0.672002, 1.109957, 0.827608, 1.272683, 0.670943, 1.068174, 0.752511, 0.878203, 
1.108504, 1.250712, 0.620039, 0.752463, 1.439216, 0.890828, 1.018300, 0.736766, 0.910504, 0.849118, 
1.222589, 1.083869, 0.627894, 1.150342, 1.377353, 0.785771, 0.679900, 0.897937, 0.854521, 0.920765, 
1.326349, 1.690290, 1.188837, 0.595281, 0.602145, 0.626852, 0.676343, 0.829212, 0.785923, 0.799661, 
1.499772, 1.400400, 0.655881, 0.892565, 1.089036, 0.702486, 0.835749, 0.800092, 0.731263, 0.835818, 
1.126664, 1.353291, 0.898265, 0.897870, 0.934461, 1.003119, 0.982470, 0.815886, 0.952342, 0.831774, 
1.316478, 1.060041, 0.667653, 1.065408, 0.910377, 1.002121, 1.339044, 0.710796, 0.720291, 0.813624, 
0.976194, 1.377380, 1.071262, 0.789567, 1.085928, 1.253806, 1.017727, 0.719049, 0.561583, 0.692329, 
1.202869, 1.059008, 0.962883, 0.999919, 0.524897, 1.074531, 1.091141, 0.910749, 1.044517, 0.859795, 
1.413976, 0.836644, 0.666408, 1.039645, 1.088087, 0.820217, 0.816371, 1.049252, 1.083270, 0.881172, 
1.388093, 0.807110, 0.781561, 0.964242, 0.973557, 1.138037, 1.026733, 0.970914, 0.866461, 0.841057, 
1.456077, 0.982162, 0.557993, 0.738683, 1.375522, 0.772422, 0.644426, 0.952329, 0.954631, 1.004692, 
1.606208, 1.220452, 0.738208, 0.744965, 0.659231, 0.813191, 0.932141, 0.922849, 0.956161, 0.892080, 
1.126839, 1.038057, 0.935449, 1.012686, 1.080640, 0.884338, 1.126468, 1.076987, 0.817224, 0.736383, 
1.215351, 0.845602, 0.829299, 1.204972, 0.891515, 0.934431, 0.887728, 0.938925, 0.955741, 1.114145, 
1.206387, 0.977863, 1.051199, 0.847855, 0.939759, 1.254109, 0.970361, 0.901040, 0.844070, 0.819544, 
1.207602, 0.976323, 0.841307, 0.870300, 0.877422, 0.988163, 0.931714, 1.031677, 1.205409, 0.903902, 
1.095130, 1.105129, 0.722843, 0.943180, 1.211443, 1.178861, 0.634252, 0.870933, 1.011727, 0.936443, 
1.032014, 0.998735, 0.686262, 1.100404, 1.022352, 1.222401, 1.146689, 0.812882, 0.927129, 0.801404, 
1.131931, 1.489739, 0.677826, 0.610733, 0.759219, 0.808122, 1.042500, 1.077132, 1.035717, 0.906736, 
1.342504, 1.076171, 0.583400, 0.764890, 0.818097, 1.293405, 1.058200, 0.852259, 0.958646, 0.872888, 
1.308520, 1.219689, 0.935572, 0.714861, 1.129251, 0.856944, 0.920880, 0.974834, 0.821443, 0.847930, 
1.372592, 0.887155, 0.710732, 1.029836, 1.278897, 0.650119, 1.136552, 0.881858, 0.850047, 0.819899, 
1.019956, 1.381944, 1.089064, 0.576825, 0.594933, 0.752016, 1.265619, 1.129530, 0.867864, 0.768122, 
1.154864, 1.069591, 0.913967, 0.796105, 0.790255, 0.854206, 1.523905, 0.856969, 0.887946, 0.756665, 
0.874806, 1.645517, 0.834275, 1.578196, 0.903996, 0.547038, 0.565520, 0.704114, 0.697290, 0.713786, 
1.153418, 1.095160, 0.870564, 1.655735, 1.071838, 0.806210, 0.607539, 0.566859, 0.683404, 0.826413, 
0.830864, 1.448871, 1.014508, 0.939034, 1.574030, 0.796490, 0.654852, 0.558685, 0.641596, 0.797132, 
1.125819, 1.396448, 0.746324, 1.295697, 1.137447, 1.301677, 0.574765, 0.486441, 0.489204, 0.608138, 
0.832614, 0.802739, 1.148272, 1.316531, 1.305743, 0.696667, 0.940671, 0.848198, 0.872696, 0.851311, 
1.260278, 0.958467, 0.667246, 1.406435, 0.859092, 0.534003, 0.485425, 0.723814, 1.418320, 0.944772, 
0.887527, 1.330678, 1.062704, 0.552689, 1.098956, 0.917567, 0.874732, 1.075172, 0.845710, 1.019528, 
0.906302, 1.326878, 0.632127, 0.781817, 1.111568, 0.753606, 0.896250, 0.945621, 0.969063, 1.304544, 
0.163798, 1.616260, 0.520967, 1.244674, 0.597986, 1.174228, 0.802735, 1.079115, 0.892800, 0.877604, 
0.717419, 1.075445, 0.997204, 1.206762, 1.312107, 1.316050, 0.696587, 0.745413, 0.739740, 0.731447, 
0.339447, 1.827655, 0.684798, 0.716559, 0.676084, 1.081139, 0.894730, 0.954454, 0.948165, 0.910477, 
0.864667, 1.451421, 0.725543, 1.176080, 1.209637, 1.083631, 1.163663, 0.662386, 0.501862, 0.463726, 
0.563978, 1.135516, 0.835026, 1.736364, 1.000137, 0.805360, 0.828496, 0.833563, 0.776277, 0.805186, 
1.009051, 1.360317, 0.668259, 1.417717, 1.518623, 0.638014, 0.446922, 0.496800, 0.693633, 0.726920, 
0.186440, 1.625134, 0.835253, 1.175778, 0.860628, 0.885086, 1.011866, 0.789303, 1.010232, 0.802450, 
0.652311, 1.599127, 0.599516, 1.058215, 0.801753, 0.992815, 1.146092, 0.829615, 0.939228, 0.837653, 
0.759780, 1.399480, 0.987329, 1.024824, 0.974458, 0.551246, 1.150852, 0.844956, 1.016771, 0.925568, 
1.069814, 1.160678, 0.803250, 1.193140, 1.112463, 0.744748, 1.070724, 0.739996, 0.924675, 0.942765, 
1.168517, 1.633441, 0.774778, 0.736824, 1.089258, 1.057042, 0.783527, 0.691403, 0.779568, 0.728487, 
1.301817, 1.572909, 0.526128, 0.558027, 0.660410, 1.078262, 1.089774, 0.718543, 0.753433, 0.965337, 
0.891795, 1.262297, 0.911545, 1.214103, 0.776010, 0.944986, 1.138773, 0.772798, 0.957464, 0.885334, 
1.219015, 1.048683, 0.943178, 1.150567, 0.837824, 0.566225, 0.660764, 1.219023, 1.019092, 0.988723, 
0.925533, 1.350162, 1.164350, 0.542695, 1.227640, 0.600203, 1.205779, 0.701896, 0.932956, 0.815466, 
1.019130, 1.292473, 0.796847, 0.819714, 1.254208, 0.522062, 1.293349, 0.823616, 0.832862, 0.890015, 
0.686388, 1.534513, 1.023273, 1.065238, 0.769952, 0.914897, 0.958226, 0.965983, 0.847693, 0.876086, 
0.560425, 1.321635, 0.837563, 1.105726, 0.800833, 0.952432, 0.673960, 1.327502, 0.806885, 1.135634, 
0.722275, 1.482196, 1.269134, 0.695424, 0.734410, 1.240968, 0.873750, 0.825209, 0.794290, 0.840055, 
1.022015, 1.408327, 0.702067, 0.966478, 0.742264, 1.204704, 0.633885, 0.888498, 0.713166, 1.231153, 
0.512817, 1.187577, 0.939995, 1.273059, 1.261853, 0.875396, 0.884657, 0.928591, 0.900721, 0.880112, 
0.781537, 1.223652, 0.854824, 0.972599, 1.347144, 0.807227, 0.911694, 0.956919, 0.990262, 0.893345, 
0.358832, 1.601542, 1.125781, 0.730841, 0.795475, 0.856229, 1.070817, 0.869601, 1.043598, 0.896567, 
0.821456, 1.676333, 0.931807, 0.740210, 0.946762, 0.917425, 0.936539, 0.884692, 0.872158, 0.827619, 
1.133434, 1.069057, 0.628708, 1.348112, 1.024242, 0.726333, 0.485013, 0.517711, 0.812878, 1.483409, 
1.439495, 0.401963, 0.704352, 1.185582, 1.196889, 0.894400, 0.762308, 0.871978, 1.004571, 0.965074, 
1.355857, 1.217795, 0.623188, 0.626000, 1.080819, 1.443039, 0.690217, 0.676470, 0.752167, 0.890824, 
1.384203, 0.893545, 0.571820, 1.422045, 1.054457, 0.896980, 0.929532, 0.779836, 0.816629, 0.774798, 
1.272930, 0.807536, 0.943865, 1.161822, 1.109685, 0.883353, 0.756987, 1.183318, 0.792499, 0.818768, 
1.368426, 0.939970, 0.927314, 1.372501, 0.966845, 0.661820, 0.817570, 0.813094, 0.874638, 0.905751, 
1.234512, 0.812394, 1.092298, 0.956999, 0.926831, 1.159350, 0.560790, 0.914404, 1.104409, 0.951357, 
1.462063, 1.107453, 0.736919, 1.182041, 0.753060, 0.817381, 0.845724, 0.960321, 0.930034, 0.870101, 
1.154263, 1.149050, 0.969239, 1.003195, 0.709246, 1.334899, 0.539388, 0.648414, 1.170228, 0.841587, 
1.363427, 0.856319, 0.848329, 1.330223, 1.580245, 0.593904, 0.534564, 0.577523, 0.647285, 0.799871, 
1.430748, 1.277622, 0.535910, 1.316419, 0.704018, 1.139968, 0.844730, 0.708186, 0.689915, 0.673166, 
1.456831, 0.852769, 0.836842, 1.661979, 0.555156, 0.659789, 0.754965, 0.765223, 0.801905, 0.871901, 
1.219340, 0.941999, 1.021315, 1.258016, 0.869648, 1.086416, 1.006363, 0.806097, 0.807889, 0.739562, 
1.269435, 1.217910, 1.091920, 1.130622, 1.241678, 0.548636, 0.659441, 0.769661, 0.738142, 0.844145, 
1.109102, 1.109600, 0.921873, 1.080103, 0.644065, 1.551581, 0.917328, 0.782032, 0.649409, 0.682361, 
1.148823, 1.115256, 0.784950, 1.519787, 0.632186, 0.880947, 0.965093, 0.738516, 0.923041, 0.843738, 
1.099162, 1.072237, 1.059239, 1.012868, 1.091543, 0.820111, 0.632757, 0.796845, 1.140959, 1.032531, 
1.382078, 1.014650, 0.855020, 1.088445, 1.147617, 1.054602, 0.759230, 0.758359, 0.828497, 0.830315, 
1.331108, 0.911897, 0.551680, 0.739304, 1.080511, 1.173246, 0.671436, 0.925538, 1.082333, 1.110124, 
1.380841, 1.130295, 0.743747, 0.910074, 0.957719, 0.986217, 0.885270, 0.809240, 0.914088, 1.051811, 
1.310270, 0.998818, 0.989857, 1.025202, 0.906801, 0.876459, 0.895856, 0.981348, 0.982188, 0.901957, 
1.442392, 0.947518, 1.052543, 0.888925, 1.092888, 0.674498, 0.920650, 0.987177, 0.890263, 0.816537, 
1.173251, 0.879037, 1.128982, 0.905439, 1.302826, 1.072854, 0.709855, 0.689286, 1.000834, 0.819403, 
1.162547, 0.939193, 1.038151, 0.930689, 0.914292, 0.877584, 1.144403, 0.667857, 1.257437, 0.810249, 
0.957634, 1.145630, 1.008914, 1.045813, 1.030746, 1.071616, 0.801657, 0.909400, 0.880216, 1.014015, 
1.250553, 1.148173, 0.606277, 0.991795, 0.997859, 0.688890, 0.942568, 0.922857, 1.233180, 0.891771, 
1.223899, 1.343365, 0.813470, 0.600631, 0.514261, 1.292102, 0.994158, 1.012705, 0.774822, 0.889761, 
1.434258, 1.190874, 0.478282, 0.454840, 0.731792, 1.170314, 0.776934, 1.201793, 0.865726, 0.993823, 
1.075483, 0.950940, 1.056806, 0.939311, 0.767863, 1.050672, 0.923138, 1.208091, 0.957328, 0.914622, 
1.152850, 0.985329, 0.758860, 0.902903, 1.268339, 0.822622, 0.951593, 0.972154, 0.988798, 1.010038, 
0.934316, 1.213602, 1.137776, 0.530840, 0.583216, 1.327735, 0.648220, 1.122533, 0.983140, 0.947688, 
1.096461, 1.329950, 1.056696, 1.096312, 0.518753, 0.667957, 1.377914, 0.802439, 0.713627, 0.728387, 
0.438479, 0.986558, 0.795180, 1.048475, 1.212747, 1.336801, 0.859633, 1.040980, 0.943136, 0.921149, 
1.106514, 0.482598, 0.612108, 1.642264, 0.798236, 0.780622, 0.825869, 0.883680, 1.122055, 0.975218, 
0.977340, 0.929082, 0.748423, 0.688517, 1.866792, 0.978102, 0.704420, 0.691328, 0.814419, 0.732273, 
2.061007, 1.317233, 0.531080, 0.663650, 0.466228, 0.673965, 0.663756, 0.680624, 0.722060, 0.735546, 
0.324483, 0.566419, 1.626532, 0.909957, 0.767043, 1.218518, 0.923857, 0.781191, 1.034489, 0.929690, 
1.132776, 0.664024, 0.658276, 1.115888, 1.058611, 0.773592, 1.143017, 1.345343, 0.885859, 0.793138, 
0.693193, 0.957946, 1.074530, 0.991271, 1.178869, 1.050262, 1.231718, 0.919607, 0.838514, 0.820971, 
0.981206, 1.282808, 0.628439, 0.831905, 0.871888, 1.000360, 1.072068, 1.359583, 0.865264, 0.714229, 
0.444708, 1.320901, 0.863009, 0.823633, 1.282252, 1.175766, 1.016159, 0.800445, 0.885734, 0.918392, 
0.524278, 0.903183, 0.842282, 0.999358, 1.663203, 0.862494, 0.990065, 0.863742, 0.861246, 0.885159, 
0.647517, 1.630489, 0.674425, 0.552789, 1.367019, 0.802523, 1.078554, 0.810538, 0.843750, 0.824923, 
1.157635, 1.168651, 0.661005, 0.556302, 1.240422, 0.970912, 0.829631, 1.237884, 0.917322, 0.831318, 
0.271398, 0.978008, 0.699287, 1.501347, 0.903792, 1.105029, 0.960131, 1.036695, 1.001109, 0.890359, 
0.275143, 0.628587, 1.143603, 1.112293, 1.315251, 1.071179, 0.889841, 0.954181, 1.018312, 0.964080, 
0.659209, 1.447333, 0.894087, 1.001992, 0.839399, 1.449942, 0.796803, 0.843993, 0.756016, 0.817636, 
0.853138, 1.064738, 0.855133, 0.742170, 0.868512, 1.370756, 0.989681, 1.038327, 0.937196, 0.993200, 
0.973539, 1.188932, 1.023116, 0.931037, 1.059522, 0.699512, 0.709015, 1.360161, 0.889684, 0.811761, 
1.226588, 1.022695, 0.719215, 1.364611, 0.676914, 0.710196, 1.255418, 1.207082, 0.643748, 0.569250, 
0.911359, 1.344114, 1.042414, 0.518823, 1.545711, 0.394875, 0.583463, 1.042424, 0.973970, 0.781663, 
1.728382, 0.630457, 0.384633, 0.410263, 0.623340, 0.756137, 0.963416, 1.240436, 1.179740, 0.957703, 
0.738959, 0.590931, 1.110580, 1.101743, 0.983178, 0.969963, 1.084357, 1.136055, 1.021410, 0.944931, 
1.244427, 0.569958, 1.057313, 1.369461, 0.723367, 0.805159, 1.027868, 1.091877, 0.873967, 0.776658, 
0.787743, 0.905228, 1.203273, 0.843008, 1.182612, 1.029414, 0.763719, 1.097128, 0.900016, 1.016990, 
1.314427, 1.012982, 0.695385, 0.878737, 0.749022, 0.792771, 1.048592, 1.421864, 0.816344, 0.837093, 
0.284264, 1.037450, 0.783668, 1.045137, 1.085681, 0.925955, 1.010468, 0.963587, 1.285465, 1.083612, 
0.182413, 0.501944, 0.613194, 0.864945, 1.046530, 1.201125, 1.222115, 1.201816, 1.144754, 1.100226, 
0.399720, 1.302627, 1.339572, 0.544091, 1.113712, 0.704227, 0.959569, 1.086265, 0.919326, 0.996120, 
1.312087, 1.234779, 1.155127, 0.573204, 0.603170, 1.675500, 0.578462, 0.549438, 0.586763, 0.627105, 
0.347498, 1.019206, 0.902255, 0.918363, 1.078096, 0.895444, 1.295650, 1.236476, 0.896594, 0.955950, 
0.228297, 0.547356, 1.316811, 1.334579, 0.850478, 0.739122, 1.162684, 1.153175, 0.961239, 0.847730, 
0.450951, 1.164991, 1.356497, 0.748838, 1.098313, 1.180630, 0.960353, 0.882357, 0.871493, 0.801907, 
1.101005, 1.177952, 1.577841, 0.463778, 0.535020, 0.573959, 0.857461, 1.214102, 0.824723, 0.827632, 
1.008192, 0.512187, 0.511630, 0.803656, 1.363784, 1.397129, 1.041883, 0.945399, 0.880500, 0.836761, 
1.333032, 0.522169, 0.512363, 0.626419, 0.780427, 0.951713, 1.495366, 1.235918, 0.888195, 0.836141, 
1.680621, 0.528954, 0.445504, 0.623836, 1.316133, 1.053039, 0.890863, 0.877480, 0.775161, 0.883213, 
2.235511, 0.589895, 0.429925, 0.577054, 0.680209, 0.667395, 0.784315, 0.803936, 0.861809, 0.801209, 
1.092796, 0.555938, 1.481165, 0.731586, 1.165349, 0.972450, 0.847847, 0.832928, 0.893096, 0.925555, 
1.276456, 0.719658, 0.981702, 1.037082, 1.176864, 0.684247, 0.782879, 0.891723, 1.117659, 1.034450, 
1.228245, 0.771626, 1.121788, 0.749934, 0.884593, 0.958108, 1.233677, 1.045060, 0.933820, 0.833295, 
1.469187, 0.712424, 0.977325, 0.707326, 1.237597, 0.953937, 0.835168, 0.794138, 0.991406, 0.934207, 
1.079164, 1.065143, 1.263724, 0.575489, 1.628970, 0.516204, 0.546497, 0.527023, 0.774807, 1.079119, 
1.337945, 0.994695, 0.675169, 0.865744, 1.373516, 1.324911, 0.866779, 0.633895, 0.599425, 0.727921, 
1.511212, 0.641169, 1.710560, 0.731522, 0.590315, 0.546117, 0.624898, 0.778970, 0.908906, 0.903649, 
1.760845, 1.236091, 1.067203, 0.487204, 0.655720, 0.713362, 0.697764, 0.749475, 0.847174, 0.921298, 
1.242002, 1.065400, 0.986706, 0.626575, 1.306310, 0.681929, 0.717473, 0.615010, 1.350818, 0.832838, 
1.114715, 0.651334, 1.082160, 1.095767, 1.064034, 1.122643, 1.004475, 0.903535, 0.874168, 0.865362, 
1.244497, 1.005714, 1.193496, 0.734583, 0.598761, 1.274922, 1.289539, 0.614727, 0.688696, 0.778442, 
1.408250, 0.839767, 1.067828, 0.572007, 0.672582, 1.239141, 0.865001, 0.858314, 1.080318, 0.941161, 
1.250488, 0.918235, 1.101326, 0.668242, 1.365644, 0.555295, 0.552784, 1.259466, 0.907460, 0.811412, 
1.631045, 0.643427, 0.448596, 0.462433, 0.721966, 1.376064, 1.149863, 0.918544, 0.813496, 0.874574, 
1.535075, 1.109493, 1.002904, 0.867410, 1.515072, 0.754291, 0.569348, 0.512821, 0.594932, 0.664862, 
1.968050, 0.717136, 1.151858, 0.741070, 0.764881, 0.686026, 0.715694, 0.699206, 0.765000, 0.778737, 
1.413788, 0.795490, 1.377022, 0.733397, 1.230761, 0.728025, 0.815985, 0.866154, 0.713555, 0.821627, 
1.339077, 0.710095, 1.014431, 1.092420, 0.988468, 0.688934, 1.213969, 0.865531, 0.928889, 0.852068, 
1.172569, 0.971105, 1.147345, 0.503528, 1.077878, 1.006880, 0.936191, 1.024685, 0.978125, 0.897520, 
1.346133, 0.825702, 1.278602, 0.712776, 0.990801, 0.824307, 0.741063, 0.777009, 1.172757, 0.958583, 
0.838360, 1.061588, 1.184451, 0.806865, 1.445930, 0.716610, 1.122729, 0.763437, 0.824729, 0.830950, 
1.276108, 0.881797, 1.013445, 0.821855, 1.264900, 1.025945, 1.227647, 0.703569, 0.659312, 0.734361, 
1.043635, 1.011762, 1.513310, 0.739962, 0.660585, 0.587323, 0.680578, 0.841721, 1.167268, 1.132996, 
1.473979, 0.627258, 1.381177, 0.659284, 0.759202, 1.049849, 1.020305, 0.870139, 0.779335, 0.834162, 
1.308547, 0.926336, 1.119570, 0.550398, 1.232051, 0.605843, 1.181402, 0.819554, 0.865953, 0.920083, 
1.337645, 0.769449, 1.229177, 0.813618, 0.735630, 0.883470, 1.569295, 0.634285, 0.606052, 0.688148, 
1.290794, 1.093894, 1.145434, 0.552063, 0.804350, 0.769436, 0.840595, 1.089482, 1.009731, 1.051359, 
1.364932, 0.913519, 1.316632, 0.718362, 0.529225, 0.723872, 1.181281, 0.876150, 0.962565, 0.918262, 
0.803741, 1.388152, 0.980932, 1.386743, 0.402886, 1.229764, 0.855613, 0.743859, 0.738745, 0.812385, 
1.187083, 1.328233, 0.750736, 1.808456, 0.498683, 0.428506, 0.498878, 0.815022, 0.756569, 0.712230, 
1.008780, 1.634667, 0.998899, 1.114864, 1.106568, 0.814867, 0.677242, 0.626767, 0.727848, 0.701162, 
1.442123, 1.578969, 1.235055, 1.279799, 0.604508, 0.459123, 0.486663, 0.548079, 0.537477, 0.639041, 
0.824699, 0.832512, 1.286809, 0.946005, 0.788899, 1.581450, 0.819352, 0.804348, 0.757910, 0.797158, 
1.173084, 0.852089, 0.837159, 1.215371, 0.614107, 0.664921, 0.798941, 1.185092, 1.404650, 0.752108, 
0.837980, 1.195548, 1.251800, 1.166862, 1.139151, 0.630036, 0.966812, 0.823920, 0.819578, 0.833867, 
1.284059, 1.360185, 0.903226, 1.260066, 0.869280, 0.794052, 0.767674, 0.784999, 0.770146, 0.814413, 
0.434909, 1.062061, 0.820721, 0.980006, 0.915903, 1.352711, 1.363232, 0.818512, 0.933755, 0.804752, 
0.140705, 0.369673, 0.761460, 1.721146, 1.281940, 0.814390, 0.770430, 0.912685, 1.029093, 0.894100, 
0.381833, 1.386068, 0.895360, 0.756433, 0.795777, 0.665474, 1.098763, 1.438104, 1.037485, 0.828884, 
0.848084, 1.088554, 0.824684, 0.776900, 0.721938, 0.676660, 0.800316, 1.135752, 1.511374, 1.057070, 
0.675218, 1.083363, 1.015844, 1.396638, 0.903676, 0.983177, 0.888414, 1.062584, 0.890620, 0.821218, 
0.754970, 0.952752, 1.127383, 1.539338, 0.700672, 0.751028, 0.640102, 0.797817, 1.188132, 0.971816, 
0.701999, 1.321737, 1.118923, 1.317673, 0.798997, 1.146361, 0.653062, 0.923909, 0.716226, 0.881342, 
0.916108, 1.387334, 0.769658, 1.200061, 0.617306, 1.096865, 0.828575, 1.077143, 0.950269, 0.767253, 
0.662335, 1.292372, 1.294051, 1.134329, 0.611097, 0.878492, 0.979876, 0.932184, 0.972586, 0.870668, 
1.081800, 1.056505, 1.431825, 1.568379, 0.608668, 0.601313, 0.533137, 0.646402, 0.768233, 0.839110, 
1.062379, 1.439992, 1.195124, 1.101291, 0.690349, 0.686199, 0.744970, 0.782839, 0.947571, 0.913290, 
1.302173, 1.079498, 1.059178, 0.961715, 0.721412, 0.548559, 0.490001, 0.649919, 1.527619, 0.917298, 
0.680923, 1.193324, 1.324460, 1.076160, 0.940757, 1.158478, 1.016504, 0.799201, 0.766968, 0.708056, 
1.013158, 0.953016, 1.286560, 1.218908, 0.634730, 1.131540, 0.788277, 0.928104, 0.871793, 0.842399, 
0.801060, 0.948640, 1.501946, 0.737009, 0.751623, 1.024697, 1.091762, 0.879438, 0.970670, 0.874395, 
1.322228, 1.272781, 1.083638, 0.879445, 0.649796, 0.924154, 0.851784, 0.949572, 0.890756, 0.876190, 
0.308295, 1.165975, 1.273902, 1.153456, 0.938787, 0.761951, 0.988352, 0.937937, 0.984994, 0.988803, 
0.307028, 0.833986, 1.891761, 1.166166, 0.526468, 0.545358, 0.772629, 0.838092, 0.849941, 1.006412, 
0.724400, 1.661022, 1.407543, 0.659395, 0.621709, 0.664584, 0.781703, 0.915312, 0.912252, 0.868291, 
0.899730, 0.520003, 2.050203, 0.570193, 0.525624, 0.618870, 0.773975, 0.953262, 0.860057, 0.852288, 
0.564036, 1.194072, 1.054038, 1.309234, 0.682175, 1.184083, 1.261020, 0.720925, 0.837966, 0.682236, 
0.705321, 0.906931, 1.440192, 1.246568, 0.945792, 0.911725, 0.914322, 0.903469, 0.819844, 0.853160, 
0.639259, 1.118893, 1.183435, 0.912825, 0.722814, 1.107206, 0.903505, 1.289695, 0.937470, 0.852877, 
0.833210, 1.220093, 1.668781, 0.922503, 0.998916, 0.696036, 0.765626, 0.779931, 0.724635, 0.754248, 
1.214346, 0.962383, 1.132890, 0.827035, 0.876470, 1.255731, 0.611676, 0.550693, 0.663031, 1.355367, 
1.790710, 0.452581, 0.576174, 0.955171, 0.930091, 0.858695, 1.025674, 0.874218, 0.875633, 0.842868, 
1.436801, 0.888196, 1.189311, 0.679367, 1.104152, 1.351368, 0.585875, 0.677641, 0.703740, 0.775152, 
1.614636, 0.783579, 0.883180, 1.156453, 0.973477, 0.848164, 0.830311, 0.892666, 0.763745, 0.831350, 
1.372060, 0.499597, 1.000811, 0.900767, 0.931695, 0.898965, 1.028259, 1.067040, 0.960141, 0.995706, 
1.464549, 0.744441, 0.906385, 0.936059, 0.731646, 0.716360, 0.829522, 1.117880, 1.156979, 1.018394, 
1.367898, 0.866499, 1.263666, 1.112268, 1.167850, 0.937974, 0.788936, 0.718079, 0.635187, 0.707080, 
1.439445, 0.795863, 0.796972, 1.211896, 0.538767, 1.255454, 0.958684, 0.857981, 0.848545, 0.824913, 
1.376381, 0.568678, 0.926291, 0.641770, 0.834535, 1.808678, 0.804428, 0.607970, 0.669675, 0.720965, 
1.355563, 0.460449, 0.596175, 1.214770, 0.946022, 1.352957, 0.860313, 0.864696, 0.785836, 0.918103, 
1.435024, 0.909544, 1.041289, 1.123733, 0.794294, 1.439099, 0.648301, 0.574374, 0.602775, 0.780902, 
1.516270, 0.918985, 0.927275, 1.189389, 0.590144, 0.748748, 1.248918, 0.683386, 0.755543, 0.882486, 
1.476744, 0.514611, 1.218581, 1.065365, 0.862836, 0.922786, 0.764142, 0.839729, 0.935193, 0.933221, 
1.315547, 0.722841, 1.311024, 1.315785, 0.913893, 0.706439, 0.682783, 0.788285, 0.877441, 0.888931, 
1.348712, 0.858988, 1.055635, 1.052220, 0.611431, 1.171928, 0.730139, 1.115700, 0.744873, 0.946277, 
1.180305, 1.053248, 0.878721, 1.288189, 0.507336, 1.103290, 0.705925, 1.007651, 0.841461, 1.044969, 
1.196638, 1.080029, 1.301461, 0.997280, 0.885975, 0.846955, 0.887870, 0.844710, 0.873575, 0.870310, 
1.373492, 1.068929, 1.077698, 1.096515, 0.998252, 0.717247, 1.234505, 0.694028, 0.663647, 0.627234, 
1.437332, 1.207382, 1.145016, 0.902884, 0.999814, 1.049959, 0.751617, 0.679969, 0.707880, 0.681629, 
1.540923, 0.966825, 1.074880, 0.967647, 0.780575, 0.824665, 0.721806, 0.771586, 0.917974, 1.059911, 
1.075058, 0.874560, 1.223286, 0.875247, 1.114946, 0.785841, 1.030228, 1.006401, 0.939058, 0.894774, 
1.230599, 0.763269, 1.223421, 1.021346, 0.751078, 0.863709, 0.928759, 0.989248, 1.037576, 0.975537, 
1.200394, 0.826452, 1.374917, 0.728714, 0.749645, 1.169742, 0.809933, 1.098679, 0.840553, 0.806698, 
1.458186, 0.835033, 1.120633, 0.933190, 0.831612, 1.053974, 1.060913, 0.785122, 0.845646, 0.769115, 
1.087334, 1.237373, 1.295267, 0.657919, 1.094758, 1.035074, 0.693941, 0.869327, 0.868297, 0.787626, 
1.183917, 0.792976, 1.143049, 0.749982, 0.626687, 0.658678, 0.983599, 1.416025, 1.044253, 0.931234, 
1.694116, 1.108393, 1.504700, 0.828677, 0.586589, 0.658925, 0.648047, 0.676080, 0.628926, 0.681370, 
1.363659, 0.859205, 1.134321, 1.227826, 0.519545, 0.570781, 0.847817, 1.035284, 0.967904, 0.993060, 
1.202407, 0.995001, 1.034142, 0.944991, 0.778536, 0.657893, 1.164819, 0.964661, 0.913810, 1.114029, 
1.325400, 0.953743, 1.087893, 1.003095, 0.754906, 0.862034, 1.119859, 1.201467, 0.736865, 0.616466, 
1.321790, 0.767809, 1.313064, 0.954328, 0.816200, 0.607967, 0.663671, 1.355803, 0.816644, 0.850276, 
1.493994, 1.117090, 1.211209, 1.311853, 0.619853, 0.708056, 0.764515, 0.708914, 0.718302, 0.743372};
