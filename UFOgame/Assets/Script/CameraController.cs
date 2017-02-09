using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class CameraController : MonoBehaviour 
{
	public Transform playerTrsansform;
	private Vector3 _offset;
	// Use this for initialization
	void Start () 
	{
		_offset = transform.position - playerTrsansform.position;
	}

	// Update is called once per frame
	void LateUpdate () 
	{
		transform.position = playerTrsansform.position + _offset;
	}
}
