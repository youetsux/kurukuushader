//������������������������������������������������������������������������������
 // �e�N�X�`�����T���v���[�f�[�^�̃O���[�o���ϐ���`
//������������������������������������������������������������������������������
Texture2D g_texture : register(t0); // �e�N�X�`���[
SamplerState g_sampler : register(s0); // �e�N�X�`���[�T���v���[

//������������������������������������������������������������������������������
 // �R���X�^���g�o�b�t�@
// DirectX �����瑗�M����Ă���A�|���S�����_�ȊO�̏����̒�`
//������������������������������������������������������������������������������
cbuffer global
{
    matrix g_matWorld; // ���_���W�ϊ��s��
    matrix g_matTexture; // �e�N�X�`�����W�ϊ��s��
    float4 g_vecColor; // �e�N�X�`������
    float2 g_angle;
};

//������������������������������������������������������������������������������
// ���_�V�F�[�_�[�o�́��s�N�Z���V�F�[�_�[���̓f�[�^�\����
//������������������������������������������������������������������������������
struct VS_OUTPUT
{
    float4 pos : SV_POSITION; // �ʒu
    float2 uv : TEXCOORD; // UV���W
};

//������������������������������������������������������������������������������
// ���_�V�F�[�_
//������������������������������������������������������������������������������
VS_OUTPUT VS(float4 pos : POSITION, float4 uv : TEXCOORD)
{
    VS_OUTPUT output;
    output.pos = mul(pos, g_matWorld);
    output.uv = mul(uv, g_matTexture);
    return output;
}

//������������������������������������������������������������������������������
// �s�N�Z���V�F�[�_
//������������������������������������������������������������������������������
float4 PS(VS_OUTPUT input) : SV_Target
{  
    float2 uvpos = float2(2.0 * input.uv.x - 1, 1.0 - 2 * input.uv.y);
    float ang = atan2(uvpos.y, uvpos.x);
    float dig = degrees(ang);
    if (dig < 0)
        dig = dig + 360;
    if (g_angle.x < g_angle.y)
    {
   
        if (dig > g_angle.x && dig < g_angle.y)
        {
            return g_vecColor * g_texture.Sample(g_sampler, input.uv);
        }
        else
            return (0, 0, 0, 0);
    }
    else if (g_angle.x > g_angle.y)
    {
        if (dig < g_angle.x && dig > g_angle.y)
        {
           return (0, 0, 0, 0);
        }
        else
           return g_vecColor * g_texture.Sample(g_sampler, input.uv);
    }else
    {
        return g_vecColor * g_texture.Sample(g_sampler, input.uv);
    }
}