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
    float2 g_angle; //��]�ł���Ȃ�p�x�������邱�Ƃɂ��悤
    int2   g_roundSetting; //��]�͔����v���H�iCounter Clock Wise)
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
    //�摜�̐^�񒆂�0,0�̍��W�n�ɕϊ��@y���̕����ŁA��]�́{�������ς���Ă���
    float2 uvpos;
    if (g_roundSetting.x)
    {
        uvpos = float2(2.0 * input.uv.x - 1, 1.0 - 2 * input.uv.y);//y�������
    }else
    {
        uvpos = float2(2.0 * input.uv.x - 1, 2 * input.uv.y - 1);//y��������
    }
    //���ݑΏۂ�u,v���W���A�ɍ��W�ɒ����p�x�𓾂�
    float dig = (degrees(atan2(uvpos.y, uvpos.x)) + 360.0) % 360.0;
    
    //g_roundSetting.y:true�̎��ˑ����Ă��^�C�}�[�@false�̎��ˌ����Ă��^�C�}�[
    if (g_roundSetting.y)
    {
        return (float) ((int) (dig < g_angle.x)) * g_vecColor * g_texture.Sample(g_sampler, input.uv);
    }
    else
    {  
        return (float) ((int) (dig > g_angle.x))*g_vecColor * g_texture.Sample(g_sampler, input.uv);
    }
}