/**
 * Description: Multiply two polynomials with arbitrary $MOD.$
 * Source: KACTL, https://cp-algorithms.com/algebra/fft.html, maroonrk
 * Verification: see FFT
 */

template<class M, class T> vector<M> go(vector<T> x, vector<T> y) {
	auto con = [](const vector<T>& v) {
		vector<M> w(sz(v)); F0R(i,sz(v)) w[i] = (int)v[i];
		return w; };
	return mul(con(x),con(y));
}
template<class T> vector<T> MUL(const vector<T>& A, const vector<T>& B) {
	using m0 = mint<(997<<20)+1,3>; // 2^20 * 997 + 1
	using m1 = mint<(1003<<20)+1,6>; // 2^20 * 1003 + 1
	using m2 = mint<(1005<<20)+1,7>; // 2^20 * 1005 + 1
	auto c0 = go<m0>(A,B); auto c1 = go<m1>(A,B); auto c2 = go<m2>(A,B);
	int n = sz(c0); vector<T> res(n);
	m1 r01 = 1/m1(m0::mod); m2 r02 = 1/m2(m0::mod), r12 = 1/m2(m1::mod);
	F0R(i,n) {
		int a = c0[i].v, b = ((c1[i]-a)*r01).v, c = ((c2[i]-a)*r02-b)*r12.v;
		res[i] = (T(c)*m1::mod+b)*m0::mod+a;
	}
	return res;
}